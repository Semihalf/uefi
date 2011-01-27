
-- BDK File menu

require("strict")
require("utils")
require("menu")

local choices = {
    "View file",
    "Copy file",
    "Delete file",
    "Execute Lua file",
    "Main menu",
}

while (true) do
    local c = menu.show(choices)
    local block_size = 128
    if (c == 1) then
        printf("Enter filename")
        local name = io.read()
        if name ~= "" then
            local f = io.open(name, "r")
            if f then
                data = f:read(block_size)
                while data do
                    io.write(data)
                    data = f:read(block_size)
                end
                f:close()
            else
                print("File not found:", name)
            end
        end
    elseif (c == 2) then
        printf("Enter source filename")
        local source = io.read()
        if source ~= "" then
            printf("Enter destination filename")
            local dest = io.read()
            if dest ~= "" then
                local s = io.open(source, "r")
                local d = io.open(dest, "w")
                data = s:read(block_size)
                while data do
                    d:write(data)
                    data = s:read(block_size)
                end
                s:close()
                d:close()
            end
        end
    elseif (c == 3) then
        printf("Enter filename")
        local name = io.read()
        if name ~= "" then
            status, result = os.remove(name)
            if not status then
                printf("ERROR: %s\n", result)
            end
        end
    elseif (c == 4) then
        printf("Enter filename")
        local name = io.read()
        if name ~= "" then
            status, result = pcall(dofile, name)
            if not status then
                printf("ERROR: %s\n", result)
            end
        end
    elseif (c == 5) then
        return
    end
end
