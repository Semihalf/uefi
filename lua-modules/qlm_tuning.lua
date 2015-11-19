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
        printf("                  'P' to change TX pre/post-emphasis, 'S' to change TX swing,\n")
        printf("                  '0' - '3' to display the eye diagram for the lane on QLM %d)\n", qlm_tuning.qlm)
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
                    if v < 1000000 then
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
            printf("Usage: CFG_TX_PREMPTAP Bits [8:5] = Tx Post Tap ; Bits [3:0] = Tx Pre Tap\n")
            for _,qlm_num in ipairs(qlm_list) do
                local csr_value = cavium.csr[menu.node].GSERX_LANEX_TX_PRE_EMPHASIS(qlm_num,0).cfg_tx_premptap
                printf("GSERX_LANEX_TX_PRE_EMPHASIS(%d,0)[CFG_TX_PREMPTAP] = 0x%x\n", qlm_num, csr_value)
                local csr_setting = menu.prompt_number("New setting for CFG_TX_PREMTAP", csr_value, 0, 511)
                local num_lanes = cavium.c.bdk_qlm_get_lanes(menu.node, qlm_num)
                for lane=0, num_lanes-1 do
                    cavium.csr[menu.node].GSERX_LANEX_TX_PRE_EMPHASIS(qlm_num,lane).cfg_tx_premptap = csr_setting
                    cavium.csr[menu.node].GSERX_LANEX_TX_CFG_1(qlm_num,lane).tx_premptap_ovrrd_val = 1
                end
                cavium.c.bdk_qlm_rx_equalization(menu.node, qlm_num, -1)
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
                    cavium.csr[menu.node].GSERX_LANEX_TX_CFG_1(qlm_num,lane).tx_swing_ovrrd_en = 1
                end
                cavium.c.bdk_qlm_rx_equalization(menu.node, qlm_num, -1)
            end
         end
         if key and (key >= '0') and (key <= '3') then
             local lane = tonumber(key)
             cavium.c.bdk_qlm_eye_display(menu.node, qlm_tuning.qlm, lane, 1, nil)
         end
    until key == '\r'
end

local function set_pre_post_tap(qlm)
    local csr_value = 0
    local num_lanes = cavium.c.bdk_qlm_get_lanes(menu.node, qlm)
    printf("Usage: CFG_TX_PREMPTAP Bits [8:5] = Tx Post Tap ; Bits [3:0] = Tx Pre Tap\n")
    for lane=0, num_lanes-1 do
        csr_value = cavium.csr[menu.node].GSERX_LANEX_TX_PRE_EMPHASIS(qlm,lane).cfg_tx_premptap
        printf("GSERX_LANEX_TX_PRE_EMPHASIS(%d,%d)[CFG_TX_PREMPTAP] = 0x%x\n", qlm, lane, csr_value)
    end
    local csr_setting = menu.prompt_number("New setting for QLM%s CFG_TX_PREMTAP" % qlm, csr_value, 0, 511)
    for lane=0, num_lanes-1 do
        cavium.csr[menu.node].GSERX_LANEX_TX_PRE_EMPHASIS(qlm,lane).cfg_tx_premptap = csr_setting
        cavium.csr[menu.node].GSERX_LANEX_TX_CFG_1(qlm,lane).tx_premptap_ovrrd_val = 1
    end
    cavium.c.bdk_qlm_rx_equalization(menu.node, qlm, -1)
end

local function set_swing_tap(qlm)
    local csr_value = 0
    local num_lanes = cavium.c.bdk_qlm_get_lanes(menu.node, qlm)
    for lane=0, num_lanes-1 do
        csr_value = cavium.csr[menu.node].GSERX_LANEX_TX_CFG_0(qlm,lane).cfg_tx_swing
        printf("GSERX_LANEX_TX_CFG_0(%d,%d)[CFG_TX_SWING] = 0x%x\n", qlm, lane, csr_value)
    end
    local csr_setting = menu.prompt_number("New setting for QLM%s CFG_TX_SWING" % qlm, csr_value, 0, 31)
    for lane=0, num_lanes-1 do
        cavium.csr[menu.node].GSERX_LANEX_TX_CFG_0(qlm,lane).cfg_tx_swing = csr_setting
        cavium.csr[menu.node].GSERX_LANEX_TX_CFG_1(qlm,lane).tx_swing_ovrrd_en = 1
    end
    cavium.c.bdk_qlm_rx_equalization(menu.node, qlm, -1)
end

local function set_gain(qlm)
    local csr_value = 0
    local num_lanes = cavium.c.bdk_qlm_get_lanes(menu.node, qlm)
    for lane=0, num_lanes-1 do
        csr_value = cavium.csr[menu.node].GSERX_LANEX_TX_CFG_3(qlm,lane).pcs_sds_tx_gain
        printf("GSERX_LANEX_TX_CFG_3(%d,%d)[PCS_SDS_TX_GAIN] = 0x%x\n", qlm, lane, csr_value)
    end
    local csr_setting = menu.prompt_number("New setting for QLM%s PCS_SDS_TX_GAIN" % qlm, csr_value, 0, 7)
    for lane=0, num_lanes-1 do
        cavium.csr[menu.node].GSERX_LANEX_TX_CFG_3(qlm,lane).pcs_sds_tx_gain = csr_setting
    end
    cavium.c.bdk_qlm_rx_equalization(menu.node, qlm, -1)
end

local function set_vboost(qlm)
    local csr_value = 0
    local num_lanes = cavium.c.bdk_qlm_get_lanes(menu.node, qlm)
    for lane=0, num_lanes-1 do
        if cavium.csr[menu.node].GSERX_LANEX_TX_CFG_1(qlm,lane).tx_vboost_en_ovrrd_en == 1 then
            csr_value = cavium.csr[menu.node].GSERX_LANEX_TX_CFG_3(qlm,lane).cfg_tx_vboost_en
        end
        printf("GSERX_LANEX_TX_CFG_3(%d,%d)[CFG_TX_VBOOST_EN] = 0x%x\n", qlm, lane, csr_value)
    end
    local csr_setting = menu.prompt_number("New setting for QLM%s CFG_TX_VBOOST_EN" % qlm, csr_value, 0, 1)
    for lane=0, num_lanes-1 do
        cavium.csr[menu.node].GSERX_LANEX_TX_CFG_3(qlm,lane).cfg_tx_vboost_en = csr_setting
        cavium.csr[menu.node].GSERX_LANEX_TX_CFG_1(qlm,lane).tx_vboost_en_ovrrd_en = 1
        cavium.csr[menu.node].GSERX_LANEX_PCS_CTLIFC_0(qlm,lane).cfg_tx_vboost_en_ovrrd_val = csr_setting
        cavium.csr[menu.node].GSERX_LANEX_PCS_CTLIFC_0(qlm,lane).cfg_tx_coeff_req_ovrrd_val = csr_setting
        cavium.csr[menu.node].GSERX_LANEX_PCS_CTLIFC_2(qlm,lane).cfg_tx_vboost_en_ovrrd_en = 1
        cavium.csr[menu.node].GSERX_LANEX_PCS_CTLIFC_2(qlm,lane).cfg_tx_coeff_req_ovrrd_en = 1
        cavium.csr[menu.node].GSERX_LANEX_PCS_CTLIFC_2(qlm,lane).ctlifc_ovrrd_req = 1
    end
    cavium.c.bdk_qlm_rx_equalization(menu.node, qlm, -1)
end

local function display_tuning_state(node, qlm, lane)
    -- Extract a number where one bits represents the sign bit
    local function s_ext(original, start_bit, stop_bit)
        local v = bit64.bextract(original, start_bit, stop_bit-1)
        local sign = bit64.bextract(original, stop_bit)
        if sign == 1 then
            v = -v
        end
        return v
    end
    local dir_label = {}
    local rx_aeq_out_0 = cavium.csr[node].GSERX_LANEX_RX_AEQ_OUT_0(qlm, lane).read()
    local rx_aeq_out_1 = cavium.csr[node].GSERX_LANEX_RX_AEQ_OUT_1(qlm, lane).read()
    local rx_aeq_out_2 = cavium.csr[node].GSERX_LANEX_RX_AEQ_OUT_2(qlm, lane).read()
    local rx_vma_status_0 = cavium.csr[node].GSERX_LANEX_RX_VMA_STATUS_0(qlm, lane).read()
    local sds_pin_mon_2 = cavium.csr[node].GSERX_LANEX_SDS_PIN_MON_2(qlm, lane).read()
    local br_rxx_eer = cavium.csr[node].GSERX_BR_RXX_EER(qlm, lane).read()
    dir_label[0] = "Hold"
    dir_label[1] = "Inc"
    dir_label[2] = "Dec"
    dir_label[3] = "Hold"

    printf("N%d.QLM%d Lane %d:\n", node, qlm, lane)
    printf("    DFE Tap 1: %d, Tap 2: %d, Tap 3: %d, Tap 4: %d, Tap 5: %d\n",
           bit64.bextract(rx_aeq_out_1, 0, 4),
           s_ext(rx_aeq_out_1, 5, 9),
           s_ext(rx_aeq_out_1, 10, 14),
           s_ext(rx_aeq_out_0, 0, 4),
           s_ext(rx_aeq_out_0, 5, 9))
    printf("    Pre-CTLE Gain: %d, Post-CTLE Gain: %d, CTLE Peak: %d, CTLE Pole: %d\n",
           bit64.bextract(rx_aeq_out_2, 4, 7),
           bit64.bextract(rx_aeq_out_2, 0, 3),
           bit64.bextract(rx_vma_status_0, 2, 6),
           bit64.bextract(rx_vma_status_0, 0, 1))
    printf("    Pre-emphasis Pre-cursor: %d, Post-cursor: %d\n",
           bit64.bextract(sds_pin_mon_2, 0, 3),
           bit64.bextract(sds_pin_mon_2, 4, 8))
    printf("    TX Boost Enable: %d, TX Turbo Mode: %d\n",
           bit64.bextract(sds_pin_mon_2, 10),
           bit64.bextract(sds_pin_mon_2, 9))
    printf("    RX Equalization Tx Directions Hints TXPRE: %s, TXMAIN: %s, TXPOST: %s, Figure of Merit: %d\n",
           dir_label[bit64.bextract(br_rxx_eer, 0,1)],
           dir_label[bit64.bextract(br_rxx_eer, 2,3)],
           dir_label[bit64.bextract(br_rxx_eer, 4,5)],
           bit64.bextract(br_rxx_eer, 6,13))
end

local function manual_rx_evaluation(qlm)
    cavium.c.bdk_qlm_rx_equalization(menu.node, qlm, -1)
    local num_lanes = cavium.c.bdk_qlm_get_lanes(menu.node, qlm_tuning.qlm)
    for lane=0, num_lanes-1 do
        display_tuning_state(menu.node, qlm, lane)
    end
end

local function do_custom(mode)
    local pattern = menu.prompt_number("10 bit pattern", 0x155, 0, 0x3ff)
    do_prbs(pattern * 256 + mode)
end

local function do_eye()
    local lane = select_lane(qlm_tuning.qlm, false)
    cavium.c.bdk_qlm_eye_display(menu.node, qlm_tuning.qlm, lane, 1, nil)
end

local function adjust_eye_params()
    local num_zeros = cavium.c.bdk_config_get_int(cavium.CONFIG_EYE_ZEROS)
    num_zeros = menu.prompt_number("Number of consecutive zeros that starts an eye", num_zeros, 1, 63)
    cavium.c.bdk_brd_cfg_set_int(num_zeros, "QLM.EYE.NUM_ZEROS")

    local settle_time = cavium.c.bdk_config_get_int(cavium.CONFIG_EYE_SETTLE_TIME);
    settle_time = menu.prompt_number("Time (us) to settle between location movements", settle_time, 1, 100000)
    cavium.c.bdk_brd_cfg_set_int(settle_time, "QLM.EYE.SETTLE_TIME");

    local sample_time = cavium.c.bdk_config_get_int(cavium.CONFIG_EYE_SAMPLE_TIME);
    sample_time = menu.prompt_number("Time (us) to count errors at each location", sample_time, 1, 10000000)
    cavium.c.bdk_brd_cfg_set_int(sample_time, "QLM.EYE.SAMPLE_TIME");
end

local function do_loopback()
    local old = cavium.csr[menu.node].GSERX_LANEX_MISC_CFG_0(qlm_tuning.qlm, 0).CFG_PCS_LOOPBACK
    local loopback = (old == 0) and 1 or 0
    if loopback == 0 then
        printf("Disabling loopback on QLM %d", qlm_tuning.qlm)
    else
        printf("Looping TX to RX on QLM %d", qlm_tuning.qlm)
    end
    local num_lanes = cavium.c.bdk_qlm_get_lanes(menu.node, qlm_tuning.qlm)
    for lane=0, num_lanes-1 do
        cavium.csr[menu.node].GSERX_LANEX_MISC_CFG_0(qlm_tuning.qlm, lane).CFG_PCS_LOOPBACK = loopback
    end
end

-- Main menu
function qlm_tuning.run()
    local m = menu.new("PRBS and SERDES Tuning Menu")
    repeat
        local num_lanes = cavium.c.bdk_qlm_get_lanes(menu.node, qlm_tuning.qlm)
        local current_qlm = (num_lanes == 2) and "DLM" or "QLM"
        current_qlm = current_qlm .. qlm_tuning.qlm
        m:item("qlm",    "Select active QLM/DLM (Currently %s)" % current_qlm, select_qlm)
        m:item("down",   "Reset and power down %s" % current_qlm, cavium.c.bdk_qlm_reset, menu.node, qlm_tuning.qlm)
        m:item("invert", "Polarity swap receive P/N on %s" % current_qlm, do_polarity_swap)
        m:item("prbs7",  "PRBS-7", do_prbs, 7)
        m:item("prbs11", "PRBS-11", do_prbs, 11)
        m:item("prbs15", "PRBS-15", do_prbs, 15)
        m:item("prbs16", "PRBS-16", do_prbs, 16)
        m:item("prbs23", "PRBS-23", do_prbs, 23)
        m:item("prbs31", "PRBS-31", do_prbs, 31)
        m:item("fixedw", "Fixed 10 bit word (PAT)", do_custom, 0x8)
        m:item("dc-bal", "DC-balanced word (PAT, ~PAT)", do_custom, 0x9)
        m:item("fixedp", "Fixed pattern (000, PAT, 3ff, ~PAT)", do_custom, 0xa)
        m:item("swing",  "Set %s TX Swing Tap" % current_qlm, set_swing_tap, qlm_tuning.qlm)
        m:item("prepost","Set %s Post and Pre TX Taps" % current_qlm, set_pre_post_tap, qlm_tuning.qlm)
        m:item("gain",  "Set %s TX Gain" % current_qlm, set_gain, qlm_tuning.qlm)
        m:item("vboost","Set %s TX VBoost" % current_qlm, set_vboost, qlm_tuning.qlm)
        m:item("rx_eval","Perform a RX equalization evaluation on %s" % current_qlm, manual_rx_evaluation, qlm_tuning.qlm)
        m:item("loop",   "Toggle loopback of TX to RX on %s" % current_qlm, do_loopback)
        m:item("eye",    "Display Eye", do_eye)
        m:item("eye-param", "Configure EYE capture parameters", adjust_eye_params)

        m:item("quit",   "Main menu")
    until (m:show() == "quit")
end

return qlm_tuning
