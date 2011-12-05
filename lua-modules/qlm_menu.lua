-- BDK QLM menu.
-- Displays the GUI interface for accessing QLM settings.
require("strict")
require("utils")
require("menu")
require("qlm")

local function show_config(qlm_num)
    local config = qlm.get_config(qlm_num)
    if config.speed == 0 then
        printf("QLM%d Mode: Disabled\n", qlm_num);
    else
        printf("QLM%d Mode: %s\n", qlm_num, config.mode);
        printf("QLM%d Gbaud: %d.%03d\n", qlm_num,
            config.speed / 1000,
            config.speed % 1000);
    end
end

local function set_config_cn61xx()
    -- Check if measured is within 10% of the reference
    local function is_ref_clock(measured, reference_mhz)
        local mhz = measured / 1000000
        local range = reference_mhz / 10
        return (mhz >= reference_mhz - range) and (mhz <= reference_mhz + range)
    end

    -- Set the speed of either QLM0 or QLM2. Doesn't support QLM1
    local function set_qlm02_speed(qlm_num, speed)
        local ref_clock = qlm.measure_clock(qlm_num)
        if is_ref_clock(ref_clock, 100) then
            -- Using 100Mhz reference
            if speed == "1250" then
                octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 3
            elseif speed == "2500" then
                octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 2
            elseif speed == "3125" then
                error("3.125 GBaud not supported with a 100Mhz reference clock")
            elseif speed == "3750" then
                error("3.750 GBaud not supported with a 100Mhz reference clock")
            elseif speed == "5000" then
                octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 0
            elseif speed == "6250" then
                error("6.250 GBaud not supported with a 100Mhz reference clock")
            else
                error("Unexpected speed selection")
            end

        elseif is_ref_clock(ref_clock, 125) then
            -- Using 125Mhz reference
            if speed == "1250" then
                octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 10
            elseif speed == "2500" then
                octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 9
            elseif speed == "3125" then
                octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 8
            elseif speed == "3750" then
                error("3.750 GBaud not supported with a 125Mhz reference clock")
            elseif speed == "5000" then
                octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 6
            elseif speed == "6250" then
                octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 5
            else
                error("Unexpected speed selection")
            end
        elseif is_ref_clock(ref_clock, 156) then
            -- Using 156.25Mhz reference
            if speed == "1250" then
                octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 4
            elseif speed == "2500" then
                octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 7
            elseif speed == "3125" then
                octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 14
            elseif speed == "3750" then
                octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 13
            elseif speed == "5000" then
                octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 11
            elseif speed == "6250" then
                octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 12
            else
                error("Unexpected speed selection")
            end
        else
            error("QLM0 reference clock is not one of the expected values. Measured: " .. tostring(ref_clock) .. " Hz")
        end
    end

    --
    -- Configure QLM0
    --
    local m = menu.new("QLM0 Mode")
    m:item("pcie",  "PCIe")
    m:item("sgmii",  "SGMII")
    m:item("xaui",  "XAUI or DXAUI")
    m:item("disabled",  "Disable QLM")
    local qlm0_mode = m:show()
    local qlm_num = 0

    if qlm0_mode == "pcie" then
        -- Ask the user if they want gen1 or gen2 so we can figure out
        -- the clock speed
        local gen2 = menu.prompt_yes_no("Configure PCIe port 0 for gen2")
        local root_complex = menu.prompt_yes_no("Configure PCIe port 0 as a root complex")
        octeon.csr.MIO_RST_CTLX(0).PRTMODE = root_complex and 1 or 0
        set_qlm02_speed(qlm_num, gen2 and "5000" or "2500")
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_CFG = 0

    elseif qlm0_mode == "sgmii" then
        -- Only support the three common speeds for running SGMII
        local m = menu.new("QLM0 Speed")
        m:item("1250",  "1.250 GBaud")
        m:item("2500",  "2.500 GBaud")
        m:item("3125",  "3.125 GBaud")
        local speed = m:show()
        set_qlm02_speed(qlm_num, speed)
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_CFG = 2

    elseif qlm0_mode == "xaui" then
        -- Support all speeds for XAUI
        local m = menu.new("QLM0 Speed")
        m:item("1250",  "1.250 GBaud")
        m:item("2500",  "2.500 GBaud")
        m:item("3125",  "3.125 GBaud")
        m:item("3750",  "3.750 GBaud")
        m:item("5000",  "5.000 GBaud")
        m:item("6250",  "6.250 GBaud")
        local speed = m:show()
        set_qlm02_speed(qlm_num, speed)
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_CFG = 3
    else
        -- Force mode of SGMII when disabling just to have a default
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_CFG = 2
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 15
    end

    --
    -- Configure QLM1
    --
    local m = menu.new("QLM1 Mode")
    m:item("1x2",  "Single PCIe with two lanes")
    if qlm0_mode ~= "pcie" then
        m:item("2x1",  "Dual PCIe with one lane each")
    end
    m:item("disabled",  "Disable QLM")
    local qlm1_mode = m:show()
    local qlm_num = 1

    if qlm1_mode == "1x2" then
        -- Ask the user if they want gen1 or gen2 so we can figure out
        -- the clock speed
        local gen2 = menu.prompt_yes_no("Configure PCIe port 1 for gen2")
        local root_complex = menu.prompt_yes_no("Configure PCIe port 1 as a root complex")
        octeon.csr.MIO_RST_CTLX(1).PRTMODE = root_complex and 1 or 0
        local ref_clock = qlm.measure_clock(qlm_num)
        if is_ref_clock(ref_clock, 100) then
            octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = gen2 and 1 or 2
        elseif is_ref_clock(ref_clock, 125) then
            octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = gen2 and 4 or 6
        else
            error("QLM0 reference clock is not one of the expected values. Measured: " .. tostring(ref_clock) .. " Hz")
        end
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_CFG = 0
    elseif qlm1_mode == "2x1" then
        -- Ask the user if they want gen1 or gen2 so we can figure out
        -- the clock speed
        local pem0_gen2 = menu.prompt_yes_no("Configure PCIe port 0 for gen2")
        local pem0_root_complex = menu.prompt_yes_no("Configure PCIe port 0 as a root complex")
        local pem1_gen2 = menu.prompt_yes_no("Configure PCIe port 1 for gen2")
        local pem1_root_complex = menu.prompt_yes_no("Configure PCIe port 1 as a root complex")
        octeon.csr.MIO_RST_CTLX(0).PRTMODE = pem0_root_complex and 1 or 0
        octeon.csr.MIO_RST_CTLX(1).PRTMODE = pem1_root_complex and 1 or 0
        local ref_clock = qlm.measure_clock(qlm_num)
        if is_ref_clock(ref_clock, 100) then
            if pem0_gen2 and pem1_gen2 then
                octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 0
            elseif pem0_gen2 then
                octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 2
            elseif pem1_gen2 then
                octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 1
            else
                octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 3
            end
        elseif is_ref_clock(ref_clock, 125) then
            if pem0_gen2 and pem1_gen2 then
                octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 4
            elseif pem0_gen2 then
                octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 6
            elseif pem1_gen2 then
                octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 9
            else
                octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 7
            end
        else
            error("QLM0 reference clock is not one of the expected values. Measured: " .. tostring(ref_clock) .. " Hz")
        end
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_CFG = 1
    else
        -- Force mode of 1x2 when disabling just to have a default
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_CFG = 0
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 15
    end

    --
    -- Configure QLM2
    --
    local m = menu.new("QLM2 Mode")
    m:item("sgmii",  "SGMII")
    m:item("xaui",  "XAUI or DXAUI")
    m:item("disabled",  "Disable QLM")
    local qlm2_mode = m:show()
    local qlm_num = 2
    if qlm2_mode == "sgmii" then
        -- Only support the three common speeds for running SGMII
        local m = menu.new("QLM2 Speed")
        m:item("1250",  "1.250 GBaud")
        m:item("2500",  "2.500 GBaud")
        m:item("3125",  "3.125 GBaud")
        local speed = m:show()
        set_qlm02_speed(qlm_num, speed)
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_CFG = 2

    elseif qlm2_mode == "xaui" then
        -- Support all speeds for XAUI
        local m = menu.new("QLM2 Speed")
        m:item("1250",  "1.250 GBaud")
        m:item("2500",  "2.500 GBaud")
        m:item("3125",  "3.125 GBaud")
        m:item("3750",  "3.750 GBaud")
        m:item("5000",  "5.000 GBaud")
        m:item("6250",  "6.250 GBaud")
        local speed = m:show()
        set_qlm02_speed(qlm_num, speed)
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_CFG = 3
    else
        -- Force mode of SGMII when disabling just to have a default
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_CFG = 2
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 15
    end
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
    if value ~= -1 then
        printf("QLM%d %s[%d]: %d (0x%04x)\n", qlm_num, field, lane, value, value)
    end
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
repeat
    if octeon.is_model(octeon.CN61XX) then
        m:item("set", "Change QLM configuration", set_config_cn61xx)
    end
    for qlm_num = 0, num_qlms-1 do
        local config = qlm.get_config(qlm_num)
        local option
        if config.speed == 0 then
            option = "QLM %d - Disabled" % qlm_num
        else
            option = "QLM %d - %s @%2d.%03d GBaud" % {qlm_num, config.mode, config.speed / 1000, config.speed % 1000}
        end
        m:item("qlm" .. qlm_num, option, qlm_submenu, qlm_num)
    end
    m:item("quit", "Main menu")
until (m:show() == "quit")


