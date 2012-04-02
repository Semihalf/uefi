---
-- Access to OCTEON QLM information.
--
-- * Written by Chad Reese
-- * Copyright (C) 2010-2012 Cavium Networks
--
require("strict")
require("utils")

qlm = {}

--- Reset a QLM
-- @param qlm_num QLM number to reset
function qlm.do_reset(qlm_num)
    -- Place QLM in power down
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_rst_n_clr", 0)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_pwrup_set", 0)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_pwrup_clr", 1)

    -- Errata (G-16467) QLM 1/2 speed at 6.25 Gbaud, excessive QLM
    -- jitter for 6.25 Gbaud
    if octeon.is_model(octeon.CN68XXP2_0) then
        -- This workaround only applies to QLMs running at 6.25Ghz
        if octeon.c.bdk_qlm_get_gbaud_mhz(qlm_num) == 6250 then
            octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "ir50dac", 10)
        end
    end

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

local function check_qlm_powerup_errata(qlm)
    -- Errata (G-16467) QLM 1/2 speed at 6.25 Gbaud, excessive QLM
    -- jitter for 6.25 Gbaud
    if octeon.is_model(octeon.CN68XXP2_0) then
        -- This workaround only applies to QLMs running at 6.25Ghz
        if octeon.c.bdk_qlm_get_gbaud_mhz(qlm) == 6250 then
            -- Ramp ir50dac from the low value used before power up
            -- to 31. This helps jitter on the QLM without affecting
            -- the divider. If ir50dac is already 31 then nothing is
            -- changed.
            local ir50dac = octeon.c.bdk_qlm_jtag_get(qlm, 0, "ir50dac")
            while ir50dac < 31 do
                ir50dac = ir50dac + 1
                octeon.c.bdk_qlm_jtag_set(qlm, -1, "ir50dac", ir50dac)
            end
        end
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

    check_qlm_powerup_errata(qlm_num)
end

--- Turn on the QLM PRBS generator. If operating in a loopback configuration
-- this also turns on the PRBS Error Counter and PRBS Lock status bit. The
-- types of PRBS generators vary by OCTEON. The scan chain bits controlling
-- the generators also vary by OCTEON.
-- @param qlm_num QLM number to run PRBS on
-- @param mode PRBS mode to run
function qlm.do_prbs(qlm_num, mode)
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

    elseif octeon.is_model(octeon.CN68XX) or octeon.is_model(octeon.CN66XX) or octeon.is_model(octeon.CN61XX) or octeon.is_model(octeon.CNF71XX) then
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

        check_qlm_powerup_errata(qlm_num)

        -- Take PRBS out of reset
        octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "jtg_prbs_tx_rst_n", 1)
        octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "jtg_prbs_rx_rst_n", 1)
    else
        error("Unsupported chip model")
    end
end


return qlm
