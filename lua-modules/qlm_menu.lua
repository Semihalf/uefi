-- BDK QLM menu.
-- Displays the GUI interface for accessing QLM settings.
require("strict")
require("utils")
require("menu")
require("qlm")

local function show_config(qlm_num)
    local config = qlm.get_config(qlm_num)
    printf("QLM%d Mode: %s\n", qlm_num, config.mode);
    printf("QLM%d Gbaud: %d.%03d\n", qlm_num,
        config.speed / 1000,
        config.speed % 1000);
end

local function set_config(qlm_num)
    assert(octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD == 15, "QLM is already configured")
    local function sgmii_config(qlm_num)
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_CFG = 2
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 3
    end

    local function xaui_config(qlm_num)
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_CFG = 3
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 8
    end

    local function dxaui_config(qlm_num)
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_CFG = 3
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 5
    end

    local function custom_config(qlm_num)
        local mode = menu.prompt_number("QLM%d Mode" % qlm_num, nil, 0, 3)
        local speed = menu.prompt_number("QLM%d Speed" % qlm_num, nil, 0, 15)
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_CFG = mode
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = speed
    end

    local prefix = "QLM" .. qlm_num
    local m = menu.new(prefix .. "Configuration")
    m:item("sgmii",  prefix .. ": SGMII 1.25Ghz", sgmii_config, qlm_num)
    m:item("xaui",   prefix .. ": XAUI  3.125Ghz", xaui_config, qlm_num)
    m:item("dxaui",  prefix .. ": DXAUI 6.25Ghz", dxaui_config, qlm_num)
    m:item("custom", prefix .. ": Custom", custom_config, qlm_num)
    m:item("quit", "Main menu")
    m:show()
end

local function measure_clock(qlm_num)
    local clock = qlm.measure_clock(qlm_num)
    printf("QLM%d Clock: %d.%03d Mhz\n", qlm_num,
        clock / 1000000,
        (clock / 1000) % 1000)
end

local function read_jtag(qlm_num)
    local num_lanes = octeon.c.bdk_qlm_get_lanes(qlm_num)
    local lane = menu.prompt_number("Lane", nil, 0, num_lanes-1)
    local field = menu.prompt_string("Field")
    local value = octeon.c.bdk_qlm_jtag_get(qlm_num, lane, field)
    printf("QLM%d %s[%d]: %d (0x%04x)\n", qlm_num, field, lane, value, value)
end

local function write_jtag(qlm_num)
    local num_lanes = octeon.c.bdk_qlm_get_lanes(qlm_num)
    local lane = menu.prompt_number("Lane (0-3, -1 for all)")
    assert((lane>=-1) and (lane<num_lanes), "Illegal lane")
    local field = menu.prompt_string("Field")
    local value = menu.prompt_number("Value")
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane, field, value)
end

local function change_tx_amplitude(qlm_num)
    local num_lanes = octeon.c.bdk_qlm_get_lanes(qlm_num)
    local lane_num = menu.prompt_number("Lane (0-3, -1 for all)", nil, -1, num_lanes-1)

    local default
    if lane_num == -1 then
        default = octeon.c.bdk_qlm_jtag_get(qlm_num, 0, "biasdrv_hs_ls_byp")
    else
        default = octeon.c.bdk_qlm_jtag_get(qlm_num, lane_num, "biasdrv_hs_ls_byp")
    end

    local biasdrv = menu.prompt_number("TX amplitude", default, 0, 31)

    -- Write ALL the biasdrvsel fields:
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "biasdrv_hs_ls_byp", biasdrv)
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "biasdrv_hf_byp", biasdrv)
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "biasdrv_lf_ls_byp", biasdrv)
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "biasdrv_lf_byp", biasdrv)

    -- Assert serdes_tx_byp to force the new settings to override the QLM default.
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "serdes_tx_byp", 1)
end

local function change_tx_demphasis(qlm_num)
    local num_lanes = octeon.c.bdk_qlm_get_lanes(qlm_num)
    local lane_num = menu.prompt_number("Lane (0-3, -1 for all)", nil, -1, num_lanes-1)

    local default
    if lane_num == -1 then
        default = octeon.c.bdk_qlm_jtag_get(qlm_num, 0, "tcoeff_hf_ls_byp")
    else
        default = octeon.c.bdk_qlm_jtag_get(qlm_num, lane_num, "tcoeff_hf_ls_byp")
    end

    local tcoeff = menu.prompt_number("TX demphasis", default, 0, 15)

    -- Write ALL the tcoeff fields:
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "tcoeff_hf_ls_byp", tcoeff)
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "tcoeff_hf_byp", tcoeff)
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "tcoeff_lf_ls_byp", tcoeff)
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "tcoeff_lf_byp", tcoeff)

    -- Assert serdes_tx_byp to force the new settings to override the QLM default.
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane_num, "serdes_tx_byp", 1)
end

local function qlm_submenu(qlm_num)
    local prefix = "QLM" .. qlm_num
    local m = menu.new(prefix .. " Menu")
    if octeon.is_model(octeon.CN61XX) then
        m:item("set", prefix .. ": Set configuration", set_config, qlm_num)
    end
    m:item("show", prefix .. ": Show configuration", show_config, qlm_num)
    m:item("clock", prefix .. ": Measure clock", measure_clock, qlm_num)
    m:item("amp", prefix .. ": Change TX amplitude", change_tx_amplitude, qlm_num)
    m:item("deemph", prefix .. ": Change TX de-emphasis", change_tx_demphasis, qlm_num)
    m:item("down", prefix .. ": Reset and power down", qlm.do_reset, qlm_num)
    if not octeon.is_model(octeon.CN63XX) then
        m:item("loop1", prefix .. ": Shallow loopback lane 0 and 3", qlm.do_loop, qlm_num, 1)
        m:item("loop3", prefix .. ": Shallow loopback lane 1 and 2", qlm.do_loop, qlm_num, 3)
    else
        m:item("loop", prefix .. ": Shallow loopback", qlm.do_loop, qlm_num, 1)
    end
    m:item("prbs7", prefix .. ": PRBS7", qlm.do_prbs, qlm_num, 7)
    if not octeon.is_model(octeon.CN63XX) then
        m:item("prbs15", prefix .. ": PRBS15", qlm.do_prbs, qlm_num, 15)
        m:item("prbs23", prefix .. ": PRBS23", qlm.do_prbs, qlm_num, 23)
    end
    m:item("prbs31", prefix .. ": PRBS31", qlm.do_prbs, qlm_num, 31)
    m:item("read", prefix .. ": Read JTAG field", read_jtag, qlm_num)
    m:item("write", prefix .. ": Write JTAG field", write_jtag, qlm_num)
    if octeon.c.bdk_qlm_dump_jtag then
        m:item("dump", prefix .. ": Dump JTAG chain", octeon.c.bdk_qlm_dump_jtag, qlm_num)
    end
    m:item("quit", "Main menu")

    while (m:show() ~= "quit") do
    -- Spinning on menu
    end
end

local m = menu.new("QLM Menu")

-- Build a list of QLMs
local num_qlms = octeon.c.bdk_qlm_get_num()
for qlm_num = 0, num_qlms-1 do
    local config = qlm.get_config(qlm_num)
    local option = "QLM %d - %s @%2d.%03d GBaud" % {qlm_num, config.mode, config.speed / 1000, config.speed % 1000}
    m:item("qlm" .. qlm_num, option, qlm_submenu, qlm_num)
end
m:item("quit", "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end


