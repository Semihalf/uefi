
-- BDK DDR menu

require("strict")
require("utils")
require("menu")

-- List of board strings that can be passed to bdk_dram_config()
local BOARD_CHOICES = {
    "ebb6300",
    "ebb6800",
}

local function ddr_config(name)
    -- Configure DDR
    local dram_size = octeon.c.bdk_dram_config(name)
    if dram_size > 0 then
        printf("Found %dMB of memory\n", dram_size)
    else
        error("Dram configuration failed.")
    end
end

-- This function is called to perform a memory test
local function memtest(start_address, length)
    printf("Testing DRR from 0x%x to 0x%x with sequential write+read\n",
        start_address, start_address + length - 1)
    local errors = octeon.c.bdk_dram_test(0, start_address, length)

    if errors < 0 then
        print("Test failed to run")
    elseif errors == 0 then
        print("Test passed")
    else
        printf("Test reported %d errors\n", errors)
    end

    printf("Testing DRR from 0x%x to 0x%x with random XOR\n",
        start_address, start_address + length - 1)
    errors = octeon.c.bdk_dram_test(1, start_address, length)

    if errors < 0 then
        print("Test failed to run")
    elseif errors == 0 then
        print("Test passed")
    else
        printf("Test reported %d errors\n", errors)
    end
end


local m = menu.new("DDR Menu")

-- Build a list of choice for each board
for _,board in ipairs(BOARD_CHOICES) do
    local text = "Initialize DDR for the \"%s\"" % board
    m:item(board, text, ddr_config, board)
end

-- Add more options for testing DDR
m:item("64MB", "Test DDR from 64MB to 128MB", memtest, 0x4000000, 0x4000000)

m:item("test", "Test DDR over a specified range", function()
    -- Test a variable range
    local start_address = menu.prompt_number("Physical byte address to start memory test at:")
    if start_address >= 0 then
        local length = menu.prompt_number("Length of region(in bytes):")
        if length > 0 then
            memtest(start_address, length)
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


