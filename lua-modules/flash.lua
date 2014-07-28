-- BDK Flash menu.
-- Displays the GUI interface for accessing NOR flash.
require("strict")
require("utils")
require("fileio")
require("menu")

local option = ""
local node = octeon.MASTER_NODE

while (option ~= "quit") do
    local m = menu.new("Flash Menu")
    m:item("init", "Query for NOR flash", function()
        octeon.c.bdk_flash_initialize(node)
    end)
    m:item("mmc-vw", "View eMMC, MMC, or SD", function()
        local chip_sel = menu.prompt_number("Chip select", 0, 0, 3)
        local offset = menu.prompt_number("Starting offset")
        local length = menu.prompt_number("Bytes to display")
        local filename = "/dev/mmc/" .. tostring(chip_sel)
        fileio.hexdump(filename, offset, length)
    end)
    m:item("mmc-wr", "Write eMMC, MMC, or SD", function()
        local chip_sel = menu.prompt_number("Chip select", 0, 0, 3)
        local source = menu.prompt_filename("Enter source filename")
        local offset = menu.prompt_number("eMMC offset")
        local filename = "/dev/mmc/" .. tostring(chip_sel)
        fileio.copy(source, nil, filename, offset)
    end)
    m:item("quit", "Main menu")
    option = m:show()
end

