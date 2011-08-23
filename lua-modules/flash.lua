
-- BDK File menu

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
    for chip=0,7 do
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
    m:item("quit", "Main menu")
    option = m:show()
end

