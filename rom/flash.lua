
-- BDK File menu

require("strict")
require("utils")
require("fileio")
require("menu")

local choices = {
    "View flash",
    "Write flash",
    "Main menu",
}

while (true) do
    local c = menu.show(choices)
    local block_size = 128
    if (c == 1) then
        printf("Starting offset")
        local offset = io.read("*n")
        if offset then
            fileio.hexdump("/dev/nor/0", offset)
        end
    elseif (c == 2) then
        printf("Enter source filename")
        local source = io.read()
        if source ~= "" then
            printf("Flash offset")
            local offset = io.read("*n")
            if offset then
                fileio.copy(source, nil, "/dev/nor/0", offset)
            end
        end
    elseif (c == 3) then
        return
    end
end
