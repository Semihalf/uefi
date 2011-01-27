
-- BDK File menu

require("strict")
require("utils")
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
            local f = io.open("/dev/nor/0", "r")
            if f then
                f:seek("set", offset)
                hexdump(f)
                f:close()
            else
                print("Flash not found")
            end
        end
    elseif (c == 2) then
        printf("Enter source filename")
        local source = io.read()
        if source ~= "" then
            printf("Flash offset")
            local offset = io.read("*n")
            if offset then
                local s = io.open(source, "r")
                local d = io.open("/dev/nor/0", "w")
                d:seek("set", offset)
                local data = s:read(block_size)
                while data do
                    d:write(data)
                    data = s:read(block_size)
                end
                s:close()
                d:close()
            end
        end
    elseif (c == 3) then
        return
    end
end
