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

-- List of board strings that can be passed to ddr.set_config()
local BOARD_CHOICES = {
    "ebb8800",
    "ebb8800_cfg1",
}

local m = menu.new("DRAM Menu")

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
            cavium.c.bdk_setenv("ddr_verbose", "yes")
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

-- Build a list of choice for each board
for _,board in ipairs(BOARD_CHOICES) do
    local text = "Initialize DRAM using config \"%s\"" % board
    m:item(board, text, function()
        local node = cavium.MASTER_NODE
        if cavium.is_model(cavium.CN88XX) then
            node = menu.prompt_number("Node to initialize", node, 0, 3)
        end
        local ddr_clock_hz = 533000000
        ddr_clock_hz = menu.prompt_number("DRAM clock Hertz", ddr_clock_hz)
        local dram_mbytes = cavium.c.bdk_dram_config_by_name(node, board, ddr_clock_hertz)
    end)
end

m:item("test", "Memory Testing Menu", menu.dofile, "ddr_test_menu")
m:item("quit", "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end


