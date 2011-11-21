---
-- Access to OCTEON QLM information.
--
-- * Written by Chad Reese
-- * Copyright (C) 2010-2011 Cavium Networks
--
require("strict")
require("utils")
local readline = require("readline")

qlm = {}

--- Get the configuration of a QLM
-- @param qlm_num QLM number to get configuration for
-- @return Table containing the QLM mode and speed
function qlm.get_config(qlm_num)
    local result = {}
    result.mode = octeon.c.bdk_qlm_get_mode(qlm_num)
    result.speed = octeon.c.bdk_qlm_get_gbaud_mhz(qlm_num)
    return result
end

--- Measure the reference clock of a QLM
-- @param qlm_num QLM number to measure
-- @return Clock frequency in hertz
function qlm.measure_clock(qlm_num)
    return octeon.c.bdk_qlm_measure_clock(qlm_num)
end

local function display_jtag_field(qlm_num, field)
    local num_lanes = octeon.c.bdk_qlm_get_lanes(qlm_num)
    printf("%20s:", field)
    for lane=0,num_lanes-1 do
        printf(" %5d", octeon.c.bdk_qlm_jtag_get(qlm_num, lane, field))
    end
    printf("\n")
end

--- Reset a QLM
-- @param qlm_num QLM number to reset
function qlm.do_reset(qlm_num)
    -- Place QLM in power down
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_rst_n_clr", 0)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_pwrup_set", 0)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_pwrup_clr", 1)

    -- Take and hold QLM out of reset
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_rst_n_set", 1)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_pwrup_clr", 0)

    -- Turn off Shallow Loopback
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "shlpbck", 0)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "sl_enable", 0)

    -- Turn off PRBS
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "jtg_prbs_rst_n", 0)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "jtg_run_prbs7", 0)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "jtg_run_prbs31", 0)
    if not octeon.is_model(octeon.CN63XX) then
        octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "jtg_prbs_tx_rst_n", 0)
        octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "jtg_prbs_rx_rst_n", 0)
    end
end

--- Turn on the QLM Shallow Loopback. Some chips can't loopback all lanes
-- at once. Which lanes are controlled by the mode parameter, which is a
-- raw JTAG value.
-- @param qlm_num QLM number to loop
-- @param mode raw JTAG value
function qlm.do_loop(qlm_num, mode)
    qlm.do_reset(qlm_num)

    -- Turn on Shallow Loopback
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "shlpbck", mode)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "sl_posedge_sample", 0)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "sl_enable", 1)

    -- Power up the QLM
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_pwrup_set", 1)

    display_jtag_field(qlm_num, "shlpbck")
    display_jtag_field(qlm_num, "sl_enable")
end

--- Turn on the QLM PRBS generator. If operating in a loopback configuration
-- this also turns on the PRBS Error Counter and PRBS Lock status bit. The
-- types of PRBS generators vary by OCTEON. The scan chain bits controlling
-- the generators also vary by OCTEON.
-- @param qlm_num QLM number to run PRBS on
-- @param mode PRBS mode to run
function qlm.do_prbs(qlm_num, mode)
    qlm.do_reset(qlm_num)

    if octeon.is_model(octeon.CN63XX) then
        --[[
            63xx PRBS:
            cfg_pwrup_set 0 (Covered in qlm.do_reset)
            cfg_pwrup_clr 1 (Covered in qlm.do_reset)
            cfg_rst_n_set 1 (Covered in qlm.do_reset)
            cfg_pwrup_set 1
            jtg_run_prbs7 1
            jtg_prbs_rst_n 1
        ]]--
        -- Power up the QLM
        octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_pwrup_set", 1)
        -- Enable PRBS7 if necessary
        octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "jtg_run_prbs7", (mode == 7))
        -- Enable PRBS31 if necessary
        octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "jtg_run_prbs31", (mode == 31))
        -- Take PRBS out of reset
        octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "jtg_prbs_rst_n", 1)

    elseif octeon.is_model(octeon.CN68XX) or octeon.is_model(octeon.CN66XX) or octeon.is_model(octeon.CN61XX) then
        --[[
            68xx PRBS:
            cfg_pwrup_set 0 (Covered in qlm.do_reset)
            cfg_pwrup_clr 1 (Covered in qlm.do_reset)
            cfg_rst_n_set 1 (Covered in qlm.do_reset)
            jtg_prbs_mode 0 (0=PRBS7, 1=PRBS15, 2=PRBS23, 3=PRBS31)
            cfg_pwrup_set 1
            jtg_prbs_tx_rst_n 1
            jtg_prbs_rx_rst_n 1
        ]]--
        if mode == 7 then
            -- 0 = PRBS7
            octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "jtg_prbs_mode", 0)
        elseif mode == 15 then
            -- 1 = PRBS15
            octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "jtg_prbs_mode", 1)
        elseif mode == 23 then
            -- 2 = PRBS23
            octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "jtg_prbs_mode", 2)
        elseif mode == 31 then
            -- 3 = PRBS31
            octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "jtg_prbs_mode", 3)
        else
            error("Illegal PRBS mode")
        end

        -- Disable pattern inversion. Octeon's default (0) has the PRBS
        -- pattern inverted. These are persistent and need clearing.
        octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_tx_pol_set", 1)
        octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_rx_pol_set", 1)

        -- Power up the QLM
        octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_pwrup_set", 1)
        -- Take PRBS out of reset
        octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "jtg_prbs_tx_rst_n", 1)
        octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "jtg_prbs_rx_rst_n", 1)
    else
        error("Unsupported chip model")
    end

    printf("PRBS%d running. Statistics shown every 5 seconds\n", mode)

    -- Periodically show the PRBS error counter and other status fields.
    local start_time = os.time()
    local next_print = start_time
    while readline.getkey() ~= '\r' do
        local t = os.time()
        if t >= next_print then
            next_print = next_print + 5
            printf("PRBS%d time: %d seconds (Press return to exit)\n", mode, t - start_time)
            display_jtag_field(qlm_num, "prbs_lock")
            display_jtag_field(qlm_num, "prbs_err_cnt")
            print()
        end
    end
end


return qlm
