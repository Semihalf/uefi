
-- BDK QLM menu

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

local function measure_clock(qlm_num)
    local clock = qlm.measure_clock(qlm_num)
    printf("QLM%d Clock: %d.%03d Mhz\n", qlm_num,
        clock / 1000000,
        (clock / 1000) % 1000)
end

local function read_jtag(qlm_num)
    local lane = menu.prompt_number("Lane", nil, 0, 3)
    local field = menu.prompt_string("Field")
    local value = octeon.c.bdk_qlm_jtag_get(qlm_num, lane, field)
    printf("QLM%d %s[%d]: %d (0x%04x)\n", qlm_num, field, lane, value, value)
end

local function write_jtag(qlm_num)
    local lane = menu.prompt_number("Lane (0-3, -1 for all)")
    assert((lane>=-1) and (lane<4), "Illegal lane")
    local field = menu.prompt_string("Field")
    local value = menu.prompt_number("Value")
    octeon.c.bdk_qlm_jtag_set(qlm_num, lane, field, value)
end

local function change_deemphasis_margin(qlm_num)
    local c = octeon.csr["CIU_QLM" .. tostring(qlm_num)].decode()
    c.TXDEEMPH = menu.prompt_number("Transmitter bypass de-emphasis value")
    c.TXMARGIN = menu.prompt_number("Transmitter bypass margin (amplitude) value")
    c.TXBYPASS = 1
    if c.G2BYPASS then
        c.G2DEEMPH = menu.prompt_number("PCIE Gen2 tx bypass de-emphasis value")
        c.G2MARGIN = menu.prompt_number("PCIE Gen2 tx bypass margin (amplitude) value")
        c.G2BYPASS = 1
    end
    octeon.csr["CIU_QLM" .. tostring(qlm_num)].encode(c)
end

local function qlm_submenu(qlm_num)
    local prefix = "QLM" .. qlm_num
    local m = menu.new(prefix .. " Menu")
    m:item("show", prefix .. ": Show configuration", show_config, qlm_num)
    m:item("clock", prefix .. ": Measure clock", measure_clock, qlm_num)
    m:item("deemph", prefix .. ": Change de-emphasis and margin", change_deemphasis_margin, qlm_num)
    m:item("down", prefix .. ": Reset and power down", qlm.do_reset, qlm_num)
    if octeon.is_model(octeon.CN68XX) or octeon.is_model(octeon.CN66XX) then
        m:item("loop1", prefix .. ": Shallow loopback lane 0 and 3", qlm.do_loop, qlm_num, 1)
        m:item("loop3", prefix .. ": Shallow loopback lane 1 and 2", qlm.do_loop, qlm_num, 3)
    else
        m:item("loop", prefix .. ": Shallow loopback", qlm.do_loop, qlm_num, 1)
    end
    m:item("prbs7", prefix .. ": PRBS7", qlm.do_prbs, qlm_num, 7)
    if octeon.is_model(octeon.CN68XX) or octeon.is_model(octeon.CN66XX) then
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
    m:item("qlm" .. qlm_num, "QLM " .. qlm_num, qlm_submenu, qlm_num)
end
m:item("quit", "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end


