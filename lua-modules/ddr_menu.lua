-- BDK DRAM menu.
-- Displays the GUI interface for configuring and testing DRAM.
require("strict")
require("utils")
require("menu")
require("fileio")

local dram_enabled = (cavium.csr.LMCX_DDR_PLL_CTL(0).RESET_N ~= 0)
if cavium.is_platform(cavium.PLATFORM_EMULATOR) then
    dram_enabled= true
end

local m
local function update_verbose_label()
    local label = "Toggle verbose output (Currently OFF)"
    if cavium.c.bdk_config_get_int(cavium.CONFIG_DRAM_VERBOSE) ~= 0 then
        label = "Toggle verbose output (Currently ON)"
    end
    m:item("verbose", label, function()
        local value = cavium.c.bdk_config_get_int(cavium.CONFIG_DRAM_VERBOSE)
        if value ~= 0 then
            cavium.c.bdk_config_set_int(0, cavium.CONFIG_DRAM_VERBOSE)
        else
            cavium.c.bdk_config_set_int(1, cavium.CONFIG_DRAM_VERBOSE)
        end
        update_verbose_label()
    end)
end

repeat
    m = menu.new("DRAM Menu")
    m:item_node() -- Adds option to choose the node number
    if not dram_enabled then
        update_verbose_label()
        m:item("init", "Initialize DRAM", function()
            local ddr_speed = cavium.c.bdk_config_get_int(cavium.CONFIG_DDR_SPEED, menu.node)
            local new_speed = menu.prompt_number("DRAM speed in MT/s, return for default", ddr_speed)
            if new_speed ~= ddr_speed then
                cavium.c.bdk_config_set_int(new_speed, cavium.CONFIG_DDR_SPEED, menu.node)
                ddr_speed = cavium.c.bdk_config_get_int(cavium.CONFIG_DDR_SPEED, menu.node)
            end
            local dram_mbytes = cavium.c.bdk_dram_config(menu.node, ddr_speed * 1000000 / 2)
            printf("BDK DRAM:%s\n", cavium.c.bdk_dram_get_info_string(menu.node))
            dram_enabled = true
        end)
    else
        m:item("tune", "DRAM Tuning", function()
            local start_time = os.time()
            cavium.c.bdk_dram_tune(menu.node)
            local end_time = os.time()
            local total_time = os.difftime(end_time, start_time)
            local hour = total_time / 3600
            local min = (total_time % 3600) / 60
            local sec = (total_time % 3600) % 60
            printf("DRAM tuning took %02d:%02d:%02d\n", hour, min, sec)
        end)
    end
    m:item("test", "Memory Testing Menu", menu.dofile, "ddr_test_menu")
    m:item("quit", "Main menu")
until (m:show() == "quit")

