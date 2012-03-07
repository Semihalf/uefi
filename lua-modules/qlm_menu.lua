-- BDK QLM menu.
-- Displays the GUI interface for accessing QLM settings.
require("strict")
require("utils")
require("menu")
require("qlm")
local qlm_tuning = require("qlm_tuning")

-- Check if measured is within 10% of the reference
local function is_ref_clock(measured, reference_mhz)
    local mhz = measured / 1000000
    local range = reference_mhz / 10
    return (mhz >= reference_mhz - range) and (mhz <= reference_mhz + range)
end

-- CN61XX: Set the speed of either QLM0 or QLM2. Doesn't support QLM1
-- CNF71XX: Set the speed of QLM0
local function set_qlm_speed(qlm_num, speed)
    local ref_clock = octeon.c.bdk_qlm_measure_clock(qlm_num)
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

-- Set the various root/endpoint bits based on the desired mode of the
-- PCIe interface
local function set_qlm_pcie(pcie_port, root_complex)
    local rc = root_complex and 1 or 0
    local ep = root_complex and 0 or 1
    if pcie_port == 1 then
        octeon.csr.CIU_SOFT_PRST1.SOFT_PRST = 1
    else
        octeon.csr.CIU_SOFT_PRST.SOFT_PRST = 1
    end
    octeon.csr.MIO_RST_CTLX(pcie_port).encode({
        PRST_LINK = rc,
        RST_LINK = ep,
        PRTMODE = rc,
        RST_DRV = rc,
        RST_RCV = 0, -- ep
        RST_CHIP = ep})
    if not root_complex then
        if pcie_port == 1 then
            octeon.csr.CIU_SOFT_PRST1.SOFT_PRST = 0
        else
            octeon.csr.CIU_SOFT_PRST.SOFT_PRST = 0
        end
    end
end

-- Chip specific configuration prompting for CN61XX
local function set_config_cn61xx()
    --
    -- Configure QLM0
    --
    local m = menu.new("QLM0 Mode")
    m:item("pcie",  "PCIe")
    m:item("sgmii",  "SGMII")
    m:item("xaui",  "XAUI")
    m:item("disabled",  "Disable QLM")
    local qlm0_mode = m:show()
    local qlm_num = 0

    if qlm0_mode == "pcie" then
        -- Ask the user if they want gen1 or gen2 so we can figure out
        -- the clock speed
        local gen2 = menu.prompt_yes_no("Configure PCIe port 0 for gen2")
        local root_complex = menu.prompt_yes_no("Configure PCIe port 0 as a root complex")
        set_qlm_speed(qlm_num, gen2 and "5000" or "2500")
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_CFG = 0
        set_qlm_pcie(0, root_complex)

    elseif qlm0_mode == "sgmii" then
        -- Only support the three common speeds for running SGMII
        local m = menu.new("QLM0 Speed")
        m:item("1250",  "1.250 GBaud")
        m:item("2500",  "2.500 GBaud")
        m:item("3125",  "3.125 GBaud")
        local speed = m:show()
        set_qlm_speed(qlm_num, speed)
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
        set_qlm_speed(qlm_num, speed)
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
        local ref_clock = octeon.c.bdk_qlm_measure_clock(qlm_num)
        if is_ref_clock(ref_clock, 100) then
            octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = gen2 and 1 or 2
        elseif is_ref_clock(ref_clock, 125) then
            octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = gen2 and 4 or 6
        else
            error("QLM0 reference clock is not one of the expected values. Measured: " .. tostring(ref_clock) .. " Hz")
        end
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_CFG = 0
        set_qlm_pcie(1, root_complex)
    elseif qlm1_mode == "2x1" then
        -- Ask the user if they want gen1 or gen2 so we can figure out
        -- the clock speed
        local pem0_gen2 = menu.prompt_yes_no("Configure PCIe port 0 for gen2")
        local pem0_root_complex = menu.prompt_yes_no("Configure PCIe port 0 as a root complex")
        local pem1_gen2 = menu.prompt_yes_no("Configure PCIe port 1 for gen2")
        local pem1_root_complex = menu.prompt_yes_no("Configure PCIe port 1 as a root complex")
        local ref_clock = octeon.c.bdk_qlm_measure_clock(qlm_num)
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
        set_qlm_pcie(0, pem0_root_complex)
        set_qlm_pcie(1, pem1_root_complex)
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
    m:item("xaui",  "XAUI")
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
        set_qlm_speed(qlm_num, speed)
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
        set_qlm_speed(qlm_num, speed)
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_CFG = 3
    else
        -- Force mode of SGMII when disabling just to have a default
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_CFG = 2
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 15
    end
end

-- Chip specific configuration prompting for CNF71XX
local function set_config_cnf71xx()
    --
    -- Configure DLM0
    --
    -- Only support the three common speeds for running SGMII
    local m = menu.new("DLM0 Speed")
    m:item("1250",  "1.250 GBaud")
    m:item("2500",  "2.500 GBaud")
    m:item("3125",  "3.125 GBaud")
    m:item("disabled",  "Disable DLM")
    local speed = m:show()
    if speed ~= "disabled" then
        octeon.csr.MIO_QLMX_CFG(0).QLM_CFG = 2
        set_qlm_speed(0, speed)
    else
        octeon.csr.MIO_QLMX_CFG(0).QLM_SPD = 15
        octeon.csr.MIO_QLMX_CFG(0).QLM_CFG = 2
    end

    --
    -- Configure DLM1
    --
    local m = menu.new("DLM1 Mode")
    m:item("1x2",  "Single PCIe with two lanes")
    m:item("2x1",  "Dual PCIe with one lane each")
    m:item("disabled",  "Disable DLM")
    local qlm1_mode = m:show()
    local qlm_num = 1

    if qlm1_mode == "1x2" then
        -- Ask the user if they want gen1 or gen2 so we can figure out
        -- the clock speed
        local gen2 = menu.prompt_yes_no("Configure PCIe port 1 for gen2")
        local root_complex = menu.prompt_yes_no("Configure PCIe port 1 as a root complex")
        local ref_clock = octeon.c.bdk_qlm_measure_clock(qlm_num)
        if is_ref_clock(ref_clock, 100) then
            octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = gen2 and 1 or 2
        elseif is_ref_clock(ref_clock, 125) then
            octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = gen2 and 4 or 6
        else
            error("QLM0 reference clock is not one of the expected values. Measured: " .. tostring(ref_clock) .. " Hz")
        end
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_CFG = 0
        set_qlm_pcie(1, root_complex)
    elseif qlm1_mode == "2x1" then
        -- Ask the user if they want gen1 or gen2 so we can figure out
        -- the clock speed
        local pem0_gen2 = menu.prompt_yes_no("Configure PCIe port 0 for gen2")
        local pem0_root_complex = menu.prompt_yes_no("Configure PCIe port 0 as a root complex")
        local pem1_gen2 = menu.prompt_yes_no("Configure PCIe port 1 for gen2")
        local pem1_root_complex = menu.prompt_yes_no("Configure PCIe port 1 as a root complex")
        local ref_clock = octeon.c.bdk_qlm_measure_clock(qlm_num)
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
        set_qlm_pcie(0, pem0_root_complex)
        set_qlm_pcie(1, pem1_root_complex)
    else
        -- Force mode of 1x2 when disabling just to have a default
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_CFG = 0
        octeon.csr.MIO_QLMX_CFG(qlm_num).QLM_SPD = 15
    end
end

--
-- Build the main QLM/DLM menu
--
local m = menu.new("QLM/DLM Menu")
repeat
    -- Add a configuration option for chips that support it
    if octeon.is_model(octeon.CN61XX) then
        m:item("set", "Change QLM/DLM configuration", set_config_cn61xx)
    end
    if octeon.is_model(octeon.CNF71XX) then
        m:item("set", "Change DLM configuration", set_config_cnf71xx)
    end
    -- Build a list of QLMs showing the current config. Selecting them
    -- does nothing
    local num_qlms = octeon.c.bdk_qlm_get_num()
    for qlm_num = 0, num_qlms-1 do
        local config_mode = octeon.c.bdk_qlm_get_mode(qlm_num)
        local config_speed = octeon.c.bdk_qlm_get_gbaud_mhz(qlm_num)
        local num_lanes = octeon.c.bdk_qlm_get_lanes(qlm_num)
        local label = (num_lanes == 2) and "DLM" or "QLM"
        local ref_clock = octeon.c.bdk_qlm_measure_clock(qlm_num)
        local option
        if config_speed == 0 then
            option = "%s %d - Disabled" % {label, qlm_num}
        else
            option = "%s %d - %s @%2d.%03d GBaud, ref %3d.%03d Mhz" % {label, qlm_num, config_mode, config_speed / 1000, config_speed % 1000, ref_clock / 1000000, ref_clock / 1000 % 1000}
        end
        m:item("qlm" .. qlm_num, option)
    end
    m:item("tune", "PRBS and SERDES Tuning", qlm_tuning.run)
    m:item("quit", "Main menu")
until (m:show() == "quit")


