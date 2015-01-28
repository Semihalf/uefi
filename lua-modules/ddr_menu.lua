-- BDK DRAM menu.
-- Displays the GUI interface for configuring and testing DRAM.
require("strict")
require("utils")
require("menu")
require("fileio")

local getenv = os.getenv
if cavium.global then
    getenv = cavium.global.os.getenv
end

-- List of config strings that can be passed to bdk_dram_config()
local CONFIG_CHOICES = {}
for i=1,10 do
    local name = cavium.c.bdk_dram_get_config_name(i-1)
    if not name then
        break
    end
    CONFIG_CHOICES[i] = name
end

local m = menu.new("DRAM Menu")
m:item_node() -- Adds option to choose the node number

local function update_verbose_label()
    local label = "Toggle verbose output (Currently OFF)"
    if getenv("ddr_verbose") then
        label = "Toggle verbose output (Currently ON)"
    end
    m:item("verbose", label, function()
        local value = getenv("ddr_verbose")
        if value then
            cavium.c.bdk_setenv("ddr_verbose", nil)
        else
            cavium.c.bdk_setenv("ddr_verbose", "1")
        end
        update_verbose_label()
    end)
end
update_verbose_label()

m:item("setenv", "Set environment variable", function()
    local name = menu.prompt_string("Name")
    local value = menu.prompt_string("Value", "")
    if value == "" then
        value = nil
    end
    cavium.c.bdk_setenv(name, value)
end)

m:item("getenv", "Get environment variable", function()
    local name = menu.prompt_string("Name")
    local value = getenv(name)
    if value then
        printf("%s = %s\n", name, value)
    else
        printf("%s is not in the environment\n", name)
    end
end)

m:item("showenv", "Show environment variables", function()
    printf("Environment variable:\n")
    cavium.c.bdk_showenv()
end)

-- Build a list of choice for each CONFIG
for _,name in ipairs(CONFIG_CHOICES) do
    local text = "Initialize DRAM using config \"%s\"" % name
    m:item(name, text, function()
        local ddr_clock_hertz = cavium.c.bdk_dram_config_get_hertz_by_name(menu.node, name)
        local ddr_clock_override = menu.prompt_number("DRAM clock Hertz, return for default", ddr_clock_hertz)
        local dram_mbytes = cavium.c.bdk_dram_config(menu.node, name, ddr_clock_override)
    end)
end

m:item("test", "Memory Testing Menu", menu.dofile, "ddr_test_menu")
m:item("quit", "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end


