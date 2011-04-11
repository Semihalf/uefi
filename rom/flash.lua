
-- BDK File menu

require("strict")
require("utils")
require("fileio")
require("menu")

local m = menu.new("Flash Menu")

m:item("view", "View flash", function()
    local offset = menu.prompt_number("Starting offset")
    local length = menu.prompt_number("Bytes to display")
    fileio.hexdump("/dev/nor/0", offset, length)
end)

m:item("write", "Write flash", function()
    local source = menu.prompt_filename("Enter source filename")
    local offset = menu.prompt_number("Flash offset")
    fileio.copy(source, nil, "/dev/nor/0", offset)
end)

m:item("quit", "Main menu")

while (m:show() ~= "quit") do
    -- Spinning on menu
end
