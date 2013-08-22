-- BDK DDR menu.
-- Displays the GUI interface for configuring and testing DRAM.
require("strict")
require("utils")
require("menu")
require("ddr")
require("fileio")

local getenv = os.getenv
if octeon.global then
    getenv = octeon.global.os.getenv
end

-- List of board strings that can be passed to ddr.set_config()
local BOARD_CHOICES = {
    "evb7000",
    "ebb7800",
}



-- This is the ddr configuration that is being operated on.  It must be
-- initialized either from a built-in board config, or loaded from an
-- external file before it can be used or modified.
declareGlobal("ddr_config", nil)

-- Default DDR clock frequency.  For now this is passed as part of the DRAM structure,
-- so for now we will just override what is in the structure when configuring DDR.
-- (Changes to this will not be reflected in dumped configurations)
declareGlobal("ddr_clock_hz", 533000000)

local function get_cur_ddr_config()
    return ddr_config
end

local m = menu.new("DDR Menu")

-- Build a list of choice for each board
for _,board in ipairs(BOARD_CHOICES) do
    local text = "Load current DDR config using \"%s\"" % board .. " board settings"
    m:item(board, text, function()
        print("Loading config for board " .. board)
        ddr_config = ddr.get_config(board)
    end)
end

m:item("load", "Load current DDR config from a file", function()
    local filename = menu.prompt_string("Filename")
    local handle = fileio.open(filename, "r")
    local data = handle:read("*a")
    handle:close()
    -- Some transfers (xmodem) get extra junk at the end which Lua doesn't like
    data = data:gsub("\26", "")
    -- Note that 'config' name is important as it must match the name
    -- used in the lua script file that represents the ddr configuration.
    declareGlobal("config", ddr.get_config())
    local f = assert(load(data))
    f()
    ddr_config = config
end)

m:item("save", "Save current DDR config to a file", function()
    local filename = menu.prompt_string("Filename")
    ddr.show_config(ddr_config, filename)
end)

-- Dump the current configuration.  Note that we need to provide an
-- anonymous function to do this otherwise the ddr_config parameter is evaluated
-- at menu creation time and is always nil
m:item("show", "Display current DDR config", function()
    ddr.show_config(ddr_config)
end)

m:item("freq", "Change DDR clock frequency", function()
    ddr_clock_hz = menu.prompt_number("DDR clock Hertz (Currently " .. ddr_clock_hz .. " Hertz)")
end)

m:item("spd_addr", "Set SPD TWSI addresses", function()
    if not ddr_config then
        print "ERROR: unable to set SPD addresses with empty config.\n"
        return
    end
    -- some constants for accessing the ddr configuration structure.
    -- arguments provided by user are 0-n (as described in HRM), but LUA
    -- indexing is 1 based, so we must be careful.
    local max_dimms = 5;
    local max_ddr_int = 4;
    local ddr_int = menu.prompt_number("DDR interface (0 - " .. max_ddr_int - 1 .. ")") + 1
    if ddr_int > max_ddr_int then
        print "ERROR: invalid ddr interface\n"
        return
    end
    local twsi_bus = menu.prompt_number("Octeon TWSI interface number  (0-4)")
    local twsi_addr

    -- clear all SPD entries for the the interface, then loop through
    -- until all entered or 0 entered to end input.
    local index

    for index = 1,max_dimms do
         ddr_config.ddr_config[ddr_int].dimm_config_table[index].spd_addrs[1] = 0
         ddr_config.ddr_config[ddr_int].dimm_config_table[index].spd_addrs[2] = 0
         ddr_config.ddr_config[ddr_int].dimm_config_table[index].spd_ptrs[1] = nil
         ddr_config.ddr_config[ddr_int].dimm_config_table[index].spd_ptrs[2] = nil
    end

    print "Enter SPD address of 0 to end input.\n"
    for index = 1,max_dimms do
        twsi_addr = menu.prompt_number("SPD address for dimm " .. index - 1)
        if twsi_addr == 0 then
            break
        end
        -- put twsi_bus in byte 1, using mult instead of bit operations....
        twsi_addr = twsi_addr + 256 * twsi_bus

        -- update the current ddr configuration
        ddr_config.ddr_config[ddr_int].dimm_config_table[index].spd_addrs[1] = twsi_addr
    end
end)

local function update_verbose_label()
    local label = "Toggle verbose output (Currently OFF)"
    if getenv("ddr_verbose") then
        label = "Toggle verbose output (Currently ON)"
    end
    m:item("verbose", label, function()
        local value = getenv("ddr_verbose")
        if value then
            octeon.c.bdk_setenv("ddr_verbose", nil)
        else
            octeon.c.bdk_setenv("ddr_verbose", "yes")
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
    octeon.c.bdk_setenv(name, value)
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

m:item("init", "Initialize DDR controller using current config", function()
    if not ddr_config then
        error "ERROR: unable to configure DDR controller with empty config.\n"
    end
    ddr.set_config(ddr_config, ddr_clock_hz)
end)

m:item("64MB", "Test DDR from 64MB to 128MB", ddr.test, 0x4000000, 0x4000000)

m:item("test", "Test DDR over a specified range", function()
    -- Test a variable range
    local start_address = menu.prompt_number("Physical byte address to start memory test at:")
    if start_address >= 0 then
        local length = menu.prompt_number("Length of region(in bytes):")
        if length > 0 then
            ddr.test(start_address, length)
        else
            print("Invalid length")
        end
    else
        print("Invalid start address")
    end
end)

m:item("quit", "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end


