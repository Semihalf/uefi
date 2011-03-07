
-- BDK DDR menu

require("strict")
require("utils")
require("menu")

-- List of board strings that can be passed to bdk_dram_config()
local board_choices = {
    "ebb6300",
    "ebb6800",
}

-- Build a list of choice for each board
local choices = {}
for _,board in ipairs(board_choices) do
    table.insert(choices, "Initialize DDR for the \"%s\"" % board)
end

-- Add more options for testing DDR
table.insert(choices, "Test DDR from 64MB to 128MB")
table.insert(choices, "Test DDR over a specified range")
table.insert(choices, "Main menu")

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

-- Loop processing menu options
while (true) do
    local c = menu.show(choices)
    if (c >= 1) and (c <= #board_choices) then
        -- Configure DDR
        local dram_size = octeon.c.bdk_dram_config(board_choices[c])
        if dram_size > 0 then
            printf("Found %dMB of memory\n", dram_size)
        else
            print("Dram configuration failed.")
        end

    elseif (c == #board_choices + 1) then
        -- Test a fixed range
        local start_address = 0x4000000
        local length = 0x4000000
        memtest(start_address, length)

    elseif (c == #board_choices + 2) then
        -- Test a variable range
        printf("Physical byte address to start memory test at:")
        local start_address = io.read("*l")
        start_address = tonumber(start_address)
        if start_address and (start_address >= 0) then
            printf("Length of region(in bytes):")
            local length = io.read("*l")
            length = tonumber(length)
            if length and (length > 0) then
                memtest(start_address, length)
            else
                print("Invalid length")
            end
        else
            print("Invalid start address")
        end

    elseif (c == #board_choices + 3) then
        -- Move up a menu level
        return
    end
end
