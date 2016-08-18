-- BDK eMMC menu.
-- Displays the GUI interface for accessing eMMC/SD.
require("strict")
require("utils")
require("fileio")
require("menu")
local readline = require("readline")

local option = ""
local PATTERNS = {0x00, 0xff, 0x55, 0xaa}

--
-- Create a "length" sector string for the given pattern. The string
-- length will be 512 * length.
--
local function get_pattern(pattern, length)
    local pat = string.char(pattern)
    pat = pat:rep(length * 512)
    return pat
end

local function do_test(chip_sel)
    local chip_sel = menu.prompt_number("Chip select", 0, 0, 3)
    local filename = utils.devfile("mmc", chip_sel)
    local handle = assert(cavium.devopen(filename, "r+"))
    local sector = 0
    for length=1,128 do
        printf("Testing %d sector accesses\n", length)
        for i,p in ipairs(PATTERNS) do
            local correct = get_pattern(p, length)
            assert(handle:seek("set", sector * 512), "Write seek failed")
            handle:write(correct)
            assert(handle:seek("set", sector * 512), "Read seek failed")
            local data = handle:read(length * 512)
            assert(#data == length * 512, "SATA read failed")
            assert(correct == data, "SATA data doesn't match pattern")
        end
        local key = readline.getkey()
        if key == '\r' then
            printf("\nAbort on key press\n")
            goto abort_key
        end
    end
::abort_key::
    handle:close()
end

while (option ~= "quit") do
    local m = menu.new("eMMC, MMC, or SD Menu")
    m:item_node() -- Adds option to choose the node number
    m:item("mmc-vw", "View eMMC, MMC, or SD", function()
        local chip_sel = menu.prompt_number("Chip select", 0, 0, 3)
        local offset = menu.prompt_number("Starting offset")
        local length = menu.prompt_number("Bytes to display")
        local filename = utils.devfile("mmc", chip_sel)
        fileio.hexdump(filename, offset, length)
    end)
    m:item("mmc-wr", "Write eMMC, MMC, or SD", function()
        local chip_sel = menu.prompt_number("Chip select", 0, 0, 3)
        local source = menu.prompt_filename("Enter source filename")
        local offset = menu.prompt_number("eMMC offset")
        local filename = utils.devfile("mmc", chip_sel)
        fileio.copy(source, nil, filename, offset)
    end)
    m:item("mmc-test", "Run automated pattern test", do_test)
    m:item("quit", "Main menu")
    option = m:show()
end

