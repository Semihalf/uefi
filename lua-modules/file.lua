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

m:item("quit",  "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end


