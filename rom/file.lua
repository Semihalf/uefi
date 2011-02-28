
-- BDK File menu

require("strict")
require("utils")
require("menu")

local choices = {
    "View file",
    "Hexdump file",
    "Copy file",
    "Delete file",
    "Execute Lua file",
    "Execute binary image file",
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
                local data = f:read(block_size)
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
        printf("Enter filename")
        local name = io.read()
        if name ~= "" then
            local f = io.open(name, "r")
            if f then
                hexdump(f)
                f:close()
            else
                print("File not found:", name)
            end
        end
    elseif (c == 3) then
        printf("Enter source filename")
        local source = io.read()
        if source ~= "" then
            printf("Enter destination filename")
            local dest = io.read()
            if dest ~= "" then
                local s = io.open(source, "r")
                local d = io.open(dest, "w")
                local data = s:read(block_size)
                while data do
                    d:write(data)
                    data = s:read(block_size)
                end
                s:close()
                d:close()
            end
        end
    elseif (c == 4) then
        printf("Enter filename")
        local name = io.read()
        if name ~= "" then
            local status, result = os.remove(name)
            if not status then
                printf("ERROR: %s\n", result)
            end
        end
    elseif (c == 5) then
        printf("Enter filename")
        local name = io.read()
        if name ~= "" then
            local status, result = pcall(dofile, name)
            if not status then
                printf("ERROR: %s\n", result)
            end
        end
    elseif (c == 6) then
        printf("Enter filename")
        local name = io.read()
        if name ~= "" then
            local paddress = octeon.c.bdk_mmap(name, 0)
            if paddress == -1 then
                print("ERROR: File does not support mmap()")
            else
                printf("Jumping to 0x%x\n", paddress)
                local status = octeon.c.bdk_jump_address(paddress)
                if status ~= 0 then
                    print("ERROR: Jump didn't succeed")
                end
            end
        end
    elseif (c == 7) then
        return
    end
end
