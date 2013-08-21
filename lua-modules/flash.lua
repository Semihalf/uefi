-- BDK Flash menu.
-- Displays the GUI interface for accessing NOR flash.
require("strict")
require("utils")
require("fileio")
require("menu")

local option = ""

while (option ~= "quit") do
    local m = menu.new("Flash Menu")
    m:item("init", "Query for NOR flash", function()
        octeon.c.bdk_flash_initialize()
    end)
    -- Only check the first two chip selects as nobody has ever put a flash
    -- on any of the others
    for chip=0,1 do
        if octeon.c.bdk_flash_get_base(chip) ~= 0 then
            local filename = "/dev/nor/" .. tostring(chip)
            local cs = "(CS" .. tostring(chip) .. ")"

            m:item("view" .. cs, "View NOR flash " .. cs, function()
                local offset = menu.prompt_number("Starting offset")
                local length = menu.prompt_number("Bytes to display")
                fileio.hexdump(filename, offset, length)
            end)

            m:item("write" .. cs, "Write NOR flash " .. cs, function()
                local source = menu.prompt_filename("Enter source filename")
                local offset = menu.prompt_number("Flash offset")
                fileio.copy(source, nil, filename, offset)
            end)
        end
    end
    m:item("mmc-ini", "Query for eMMC, MMC, or SD", function()
        local mmc_size = octeon.mmc.init()
        printf("Found device of size %d bytes\n", mmc_size)
    end)
    m:item("mmc-vw", "View eMMC, MMC, or SD", function()
        local offset = menu.prompt_number("Starting offset")
        local length = menu.prompt_number("Bytes to display")
        while length > 0 do
            local data = octeon.mmc.read(offset, 512)
            for i=1,512,32 do
                printf("%08x: %s\n", offset, data:sub(i,i+31):hex())
                offset = offset + 32
            end
            length = length - 512
        end
    end)
    m:item("mmc-wr", "Write eMMC, MMC, or SD", function()
        local source = menu.prompt_filename("Enter source filename")
        local offset = menu.prompt_number("eMMC offset")
        local f = fileio.open(source, "r")
        repeat
            local data = f:read(512)
            if data then
                if #data < 512 then
                    data = data .. string.rep("\0", 512 - #data)
                end
                octeon.mmc.write(offset, data)
            end
            offset = offset + 512
        until data == nil
        f:close()
    end)
    m:item("quit", "Main menu")
    option = m:show()
end

