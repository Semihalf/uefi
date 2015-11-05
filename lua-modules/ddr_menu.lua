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

-- List of config strings that can be passed to bdk_dram_config()
local CONFIG_CHOICES = {}
if not dram_enabled then
    for i=1,10 do
        local name = cavium.c.bdk_dram_get_config_name(i-1)
        if not name then
            break
        end
        CONFIG_CHOICES[i] = name
    end
end

local m = menu.new("DRAM Menu")
m:item_node() -- Adds option to choose the node number

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
if not dram_enabled then
    update_verbose_label()
end

-- Build a list of choice for each CONFIG
for _,name in ipairs(CONFIG_CHOICES) do
    local text = "Initialize DRAM using config \"%s\"" % name
    m:item(name, text, function()
        local ddr_clock_hertz = cavium.c.bdk_dram_config_get_hertz_by_name(menu.node, name)
        local ddr_clock_override = menu.prompt_number("DRAM clock Hertz, return for default", ddr_clock_hertz)
        local dram_mbytes = cavium.c.bdk_dram_config(menu.node, name, ddr_clock_override)
        local clock_mhz = ddr_clock_override / 1000000
        printf("BDK DRAM: %s MB, %s MHz\n", dram_mbytes, clock_mhz)
    end)
end

m:item("test", "Memory Testing Menu", menu.dofile, "ddr_test_menu")
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
m:item("quit", "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end


