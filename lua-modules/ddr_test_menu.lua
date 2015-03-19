-- BDK DRAM test menu.
-- Displays the GUI interface for configuring and testing DRAM.
require("strict")
require("utils")
require("menu")

local range_repeat = 1
local range_start = 0
local range_length = -1

local abort_on_error = 1

local function toggle_abort_on_error()
    abort_on_error = 1 - abort_on_error
end

local function set_range_repeat()
    local count = menu.prompt_number("Number of time to repeat the test, or -1 for infinite", range_repeat)
    if (count < -1) or (count == 0) then
        print("Invalid repeat count")
    else
        range_repeat = count
    end
end

local function set_range_start()
    local start_address = menu.prompt_number("Physical byte address to start memory test at", range_start)
    if ((start_address < 0) or
        ((start_address >= 0x10000000) and (start_address < 0x20000000))) then
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
    return cavium.c.bdk_dram_test(test_number, range_start, length)
end

local function run_all_tests()
    local errors = 0
    local start_time = os.time()
    for test_number=0,100 do
	local one_errors = 0
        local name = cavium.c.bdk_dram_get_test_name(test_number);
        if not name then
            break
        end
        one_errors = run_one_test(test_number)
	errors = errors + one_errors
        if (one_errors ~= 0) and (abort_on_error == 1) then
	    break
        end
    end
    local end_time = os.time()
    if errors == 0 then
        local total_time = os.difftime(end_time, start_time)
        local hour = total_time / 3600
        local min = (total_time % 3600) / 60
        local sec = (total_time % 3600) % 60
        printf("All tests passed (time %d:%d:%d)\n", hour, min, sec)
    else
        error("Tests reported %d errors" % errors)
    end
    return errors
end

local function run_special_tests()
    local errors = 0
    local start_time = os.time()
    local special_tests = { 2, 3, 4, 12 }
    for _,test_number in ipairs(special_tests)  do
	local one_errors = 0
        local name = cavium.c.bdk_dram_get_test_name(test_number);
        if not name then
            break
        end
        one_errors = run_one_test(test_number)
	errors = errors + one_errors
        if (one_errors ~= 0) and (abort_on_error == 1) then
	    break
        end
    end
    local end_time = os.time()
    if errors == 0 then
        local total_time = os.difftime(end_time, start_time)
        local hour = total_time / 3600
        local min = (total_time % 3600) / 60
        local sec = (total_time % 3600) % 60
        printf("All tests passed (time %d:%d:%d)\n", hour, min, sec)
    else
        error("Tests reported %d errors" % errors)
    end
    return errors
end

local function do_test(test_func, arg)
    local total = range_repeat
    if total == -1 then
        total = 0x7fffffffffffffff
    end
    for count=1,total do
        if range_repeat == -1 then
            printf("Pass %d\n", count)
        else
            printf("Pass %d of %d\n", count, total)
        end
        local errors = test_func(arg)
        if (errors ~= 0) and (abort_on_error == 1) then
            break
        end
    end
end

repeat
    local m = menu.new("DRAM Test Menu")
    m:item("cores", "Bringup Cores for multi-core testing",
           cavium.c.bdk_init_nodes, 0, 0)
    if range_repeat == -1 then
        m:item("repeat", "Number of time to repeat the test (Forever)" % range_repeat, set_range_repeat)
    else
        m:item("repeat", "Number of time to repeat the test (%d)" % range_repeat, set_range_repeat)
    end
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
    m:item("all", "Run all DRAM tests", do_test, run_all_tests, nil)
    for test_number=0,100 do
        local name = cavium.c.bdk_dram_get_test_name(test_number);
        if not name then
            break
        end
        m:item("test%d" % test_number, name, do_test, run_one_test, test_number)
    end
    m:item("spec", "Run special DRAM tests", do_test, run_special_tests, nil)

    if abort_on_error == 1 then
        m:item("abort", "Abort on Errors (Currently ON)", toggle_abort_on_error)
    else
        m:item("abort", "Abort on Errors (Currently OFF)", toggle_abort_on_error)
    end

    m:item("quit", "Main menu")
until m:show() == "quit"

