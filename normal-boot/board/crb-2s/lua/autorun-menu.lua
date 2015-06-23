
-- Get the menu that is being shown
local m = arg[1]

-- Add a new item to the main menu
if m.title == "Main Menu" then
    local test = require("board-test")
    m:item("brdtest", "Run board test", test)
end
