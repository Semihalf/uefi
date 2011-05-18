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
    printf("%20s: %4d %4d %4d %4d\n", field,
        octeon.c.bdk_qlm_jtag_get(qlm_num, 0, field),
        octeon.c.bdk_qlm_jtag_get(qlm_num, 1, field),
        octeon.c.bdk_qlm_jtag_get(qlm_num, 2, field),
        octeon.c.bdk_qlm_jtag_get(qlm_num, 3, field))
end

function qlm.do_loop(qlm_num)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_rst_n_clr", 0)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_pwrup_set", 0)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_pwrup_clr", 1)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_rst_n_set", 1)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_pwrup_set", 1)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_pwrup_clr", 0)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "shlpbck", 1)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "sl_posedge_sample", 0)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "sl_enable", 1)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_rst_n_set", 1)
end

function qlm.do_prbs(qlm_num, mode)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_rst_n_clr", 0)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_pwrup_set", 0)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_pwrup_clr", 1)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_rst_n_set", 1)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_pwrup_set", 1)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "cfg_pwrup_clr", 0)
    octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "jtg_prbs_rst_n", 1)

    if mode == 7 then
        octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "jtg_run_prbs7", 1)
    else
        octeon.c.bdk_qlm_jtag_set(qlm_num, -1, "jtg_run_prbs31", 1)
    end

    while true do
        sleep(5)
        display_jtag_field(qlm_num, "jtg_run_prbs7")
        display_jtag_field(qlm_num, "jtg_run_prbs31")
        display_jtag_field(qlm_num, "prbs_lock")
        display_jtag_field(qlm_num, "prbs_err_cnt")
        print()
    end
end


return qlm
