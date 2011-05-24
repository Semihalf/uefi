require("strict")
require("utils")

qlm = {}

local function sleep(sec)
    local t = os.time() + sec
    while os.time() < t do
        -- Spin
    end
end

function qlm.get_config(qlm_num)
    local result = {}
    result.mode = octeon.c.bdk_qlm_get_mode(qlm_num)
    result.speed = octeon.c.bdk_qlm_get_gbaud_mhz(qlm_num)
    return result
end

function qlm.measure_clock(qlm_num)
    return octeon.c.bdk_qlm_measure_clock(qlm_num)
end

local function display_jtag_field(qlm_num, field)
    printf("%20s: %5d %5d %5d %5d\n", field,
        octeon.c.bdk_qlm_jtag_get(qlm_num, 0, field),
        octeon.c.bdk_qlm_jtag_get(qlm_num, 1, field),
        octeon.c.bdk_qlm_jtag_get(qlm_num, 2, field),
        octeon.c.bdk_qlm_jtag_get(qlm_num, 3, field))
end

function qlm.do_reset(qlm_num)
    -- Place QLM in power down
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_pwrup_set", 0)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_pwrup_clr", 1)
    -- Take and hold QLM out of reset
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_rst_n_set", 1)

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

    elseif octeon.is_model(octeon.CN68XX) or octeon.is_model(octeon.CN66XX) then
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
    while true do
        sleep(5)
	    printf("time: %d seconds\n" % (os.time() - start_time))
        display_jtag_field(qlm_num, "prbs_lock")
        display_jtag_field(qlm_num, "prbs_err_cnt")
        print()
    end
end


return qlm
