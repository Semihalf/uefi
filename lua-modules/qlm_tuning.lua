-- BDK QLM menu.
-- Displays the GUI interface for accessing QLM settings.
require("strict")
require("utils")
require("menu")
local readline = require("readline")

local qlm_tuning = {}
local node = octeon.MASTER_NODE
qlm_tuning.qlm = 0

-- Prompt for which QLM/DLM to edit
local function select_qlm()
    local num_qlms = octeon.c.bdk_qlm_get_num(node)
    qlm_tuning.qlm = menu.prompt_number("QLM/DLM", qlm_tuning.qlm, 0, num_qlms-1)
    return qlm_tuning.qlm
end

-- Prompt for which lane to edit
local function select_lane(qlm_num, allow_all)
    local num_lanes = octeon.c.bdk_qlm_get_lanes(node, qlm_num)
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
    local num_qlms = octeon.c.bdk_qlm_get_num(node)
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

-- Start PRBS on a list of QLMs
local function start_prbs(mode, qlm_list)
    -- Reset the QLMs. Do this independently from PRBS so that all
    -- resets are complete before we start PRBS
    for _,qlm_num in ipairs(qlm_list) do
        octeon.c.bdk_qlm_reset(node, qlm_num)
    end
    -- Start PRBS on the QLMs.
    for _,qlm_num in ipairs(qlm_list) do
        octeon.c.bdk_qlm_enable_prbs(node, qlm_num, mode, 1)
    end
    -- Let TX run for 1ms before starting RX
    octeon.c.bdk_wait_usec(1000)
    for _,qlm_num in ipairs(qlm_list) do
        octeon.c.bdk_qlm_enable_prbs(node, qlm_num, mode, 2)
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
            local num_lanes = octeon.c.bdk_qlm_get_lanes(node, qlm_num)
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
            output_line(qlm_base, "PRBS Errors", function(qlm, lane)
                local v = octeon.c.bdk_qlm_get_prbs_errors(node, qlm, lane)
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
            output_line(qlm_base, "PRBS Error Rate", function(qlm, lane)
                local qlm_speed = octeon.c.bdk_qlm_get_gbaud_mhz(node, qlm)
                local v = octeon.c.bdk_qlm_get_prbs_errors(node, qlm, lane)
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

-- Main menu
function qlm_tuning.run()
    local m = menu.new("PRBS and SERDES Tuning Menu")
    repeat
        local num_lanes = octeon.c.bdk_qlm_get_lanes(node, qlm_tuning.qlm)
        local current_qlm = (num_lanes == 2) and "DLM" or "QLM"
        current_qlm = current_qlm .. qlm_tuning.qlm
        m:item("qlm",    "Select active QLM/DLM (Currently %s)" % current_qlm, select_qlm)
        m:item("down",   "Reset and power down", octeon.c.bdk_qlm_reset, node, qlm_tuning.qlm)
        m:item("prbs7",  "PRBS-7", do_prbs, 7)
        m:item("prbs15", "PRBS-15", do_prbs, 15)
        m:item("prbs23", "PRBS-23", do_prbs, 23)
        m:item("prbs31", "PRBS-31", do_prbs, 31)
        m:item("quit",   "Main menu")
    until (m:show() == "quit")
end

return qlm_tuning
