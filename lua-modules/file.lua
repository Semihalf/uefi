-- BDK File menu.
-- Displays the GUI interface for accessing the filesystem.
require("strict")
require("utils")
require("fileio")
require("menu")

local m = menu.new("File Menu")

m:item("view",  "View file", function()
    local name = menu.prompt_filename("Enter filename")
    fileio.copy(name, nil, io.output())
end)

m:item("hex",   "Hexdump file", function()
    local name = menu.prompt_filename("Enter filename")
    local offset = menu.prompt_number("Starting offset")
    local length = menu.prompt_number("Bytes to display")
    fileio.hexdump(name, offset, length)
end)

m:item("copy",  "Copy file", function()
    local source = menu.prompt_filename("Enter source filename")
    local dest = menu.prompt_filename("Enter destination filename")
    fileio.copy(source, nil, dest)
end)

m:item("rm",    "Delete file", function()
    local name = menu.prompt_filename("Enter filename")
    local status, result = os.remove(name)
    if not status then
        printf("ERROR: %s\n", result)
    end
end)

m:item("lua",   "Execute Lua file", function()
    local name = menu.prompt_filename("Enter filename")
    local status, result = pcall(dofile, name)
    if not status then
        printf("ERROR: %s\n", result)
    end
end)

m:item("bin",   "Execute binary image file", function()
    local name = menu.prompt_filename("Enter filename")
    local paddress = cavium.c.bdk_mmap(name, 0)
    if paddress == -1 then
        print("ERROR: File does not support mmap()")
    else
        printf("Jumping to 0x%x\n", paddress)
        local status = cavium.c.bdk_jump_address(paddress)
        if status ~= 0 then
            print("ERROR: Jump didn't succeed")
        end
    end
end)

m:item("uboot", "Chain load Uboot", function()
    local source = menu.prompt_filename("Enter filename for Uboot")
    -- Uboot needs to be at a 4MB boundary
    fileio.copy(source, nil, "/dev/mem", 0x400000)
    cavium.c.bdk_write_env()
    local status = cavium.c.bdk_jump_address(0xffffffff80400000)
    if status ~= 0 then
        print("ERROR: Jump to Uboot didn't succeed")
    end
end)

m:item("quit",  "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end


