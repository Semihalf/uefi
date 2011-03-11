
-- BDK File menu

require("strict")
require("utils")
require("fileio")
require("menu")

local m = menu.new("File Menu")

m:item("view",  "View file", function()
    printf("Enter filename")
    local name = io.read()
    if name ~= "" then
        fileio.copy(name, nil, io.output())
    end
end)

m:item("hex",   "Hexdump file", function()
    printf("Enter filename")
    local name = io.read()
    if name ~= "" then
        fileio.hexdump(name)
    end
end)

m:item("copy",  "Copy file", function()
    printf("Enter source filename")
    local source = io.read()
    if source ~= "" then
        printf("Enter destination filename")
        local dest = io.read()
        if dest ~= "" then
            fileio.copy(source, nil, dest)
        end
    end
end)

m:item("rm",    "Delete file", function()
    printf("Enter filename")
    local name = io.read()
    if name ~= "" then
        local status, result = os.remove(name)
        if not status then
            printf("ERROR: %s\n", result)
        end
    end
end)

m:item("lua",   "Execute Lua file", function()
    printf("Enter filename")
    local name = io.read()
    if name ~= "" then
        local status, result = pcall(dofile, name)
        if not status then
            printf("ERROR: %s\n", result)
        end
    end
end)

m:item("bin",   "Execute binary image file", function()
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
end)

m:item("uboot", "Chain load Uboot", function()
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
end)

m:item("quit",  "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end


