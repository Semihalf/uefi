-- BDK DRAM test menu.
-- Displays the GUI interface for configuring and testing DRAM.
require("strict")
require("utils")
require("menu")
require("ddr")
require("fileio")

local range_start = 0
local range_length = -1

local function set_range_start()
    local start_address = menu.prompt_number("Physical byte address to start memory test at", range_start)
    if ((start_address < 0) or
        ((start_address >= 0x10000000) and (start_address >= 0x10000000))) then
        print("Invalid start address")
    else
        range_start = start_address
    end
end

local function set_range_length()
    local length = menu.prompt_number("Length of region in bytes, or -1 for all of memory", range_length)
    if length < -1 then
        print("Invalid length")
    else
        range_length = length
    end
end

local function run_one_test(test_number)
    local length = range_length
    if length == -1 then
        length = 0x10000000000
    end
    return octeon.c.bdk_dram_test(test_number, range_start, length)
end

local function run_all_tests()
    local errors = -1
    for test_number=0,100 do
        local name = octeon.c.bdk_dram_get_test_name(test_number);
        if not name then
            break
        end
        errors = run_one_test(test_number)
        if errors ~= 0 then
            break
        end
    end
    if errors < 0 then
        error("DRAM test failed to run")
    elseif errors == 0 then
        print("All tests passed")
    else
        error("Test reported %d errors" % errors)
    end
end


repeat
    local m = menu.new("DRAM Test Menu")
    m:item("cores", "Bringup Cores for multi-core testing",
           octeon.c.bdk_init_nodes)
    m:item("start", "Starting address (0x%x)" % range_start, set_range_start)
    if range_length == -1 then
        m:item("length", "Length of the range to check (All)" % range_length, set_range_length)
    else
        m:item("length", "Length of the range to check (0x%x)" % range_length, set_range_length)
    end
    m:item("64MB", "Set test range from 64MB to 128MB", function()
        range_start = 0x4000000
        range_length = 0x4000000
    end)
    m:item("all", "Run all DRAM tests", run_all_tests)
    for test_number=0,100 do
        local name = octeon.c.bdk_dram_get_test_name(test_number);
        if not name then
            break
        end
        m:item("test%d" % test_number, name, run_one_test, test_number)
    end

    m:item("quit", "Main menu")
until m:show() == "quit"

