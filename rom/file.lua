
-- BDK File menu

require("strict")
require("utils")
require("fileio")
require("menu")

local choices = {
    "View file",
    "Hexdump file",
    "Copy file",
    "Delete file",
    "Execute Lua file",
    "Execute binary image file",
    "Chain load Uboot",
    "Main menu",
}

while (true) do
    local c = menu.show(choices)
    local block_size = 128
    if (c == 1) then
        printf("Enter filename")
        local name = io.read()
        if name ~= "" then
            fileio.copy(name, nil, io.output())
        end
    elseif (c == 2) then
        printf("Enter filename")
        local name = io.read()
        if name ~= "" then
            fileio.hexdump(name)
        end
    elseif (c == 3) then
        printf("Enter source filename")
        local source = io.read()
        if source ~= "" then
            printf("Enter destination filename")
            local dest = io.read()
            if dest ~= "" then
                fileio.copy(source, nil, dest)
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
        printf("Enter filename for Uboot")
        local source = io.read()
        if source ~= "" then
            -- Uboot needs to be at a 4MB boundary
            fileio.copy(source, nil, "/dev/mem", 0x400000)
        end
        octeon.c.bdk_write_env()
        local status = octeon.c.bdk_jump_address(0xffffffff80400000)
        if status ~= 0 then
            print("ERROR: Jump to Uboot didn't succeed")
        end
    elseif (c == 8) then
        return
    end
end
