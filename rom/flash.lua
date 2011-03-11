
-- BDK File menu

require("strict")
require("utils")
require("fileio")
require("menu")

local m = menu.new("Flash Menu")

m:item("view", "View flash", function()
    printf("Starting offset")
    local offset = io.read("*n")
    if offset then
        fileio.hexdump("/dev/nor/0", offset)
    end
end)

m:item("write", "Write flash", function()
    printf("Enter source filename")
    local source = io.read()
    if source ~= "" then
        printf("Flash offset")
        local offset = io.read("*n")
        if offset then
            fileio.copy(source, nil, "/dev/nor/0", offset)
        end
    end
end)

m:item("quit", "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end
