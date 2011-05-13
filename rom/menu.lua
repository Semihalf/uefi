require("strict")
require("utils")

menu = {}

-- Shown before and after menu titles
local BANNER = "================================="

--
-- Called when the user calls m:item()
-- Adds or updates a menu item.
-- key = object returned when the menu item is chosen
-- description = Text shown to the user
-- func = Optional function to call when the item is chosen
-- ... = Optional arguments for the function
-- No return from this function
--
local function set_item(m, key, description, func, ...)
    local item =  {key=key, description=description, func=func, args=table.pack(...)}
    for i = 1,#m.items do
        if m.items[i].key == key then
            m.items[i] = item
            return
        end
    end
    table.insert(m.items, item)
end

--
-- Called when the user calls m:show()
-- Shows a menu on the console. Returns the item key that is selected.
-- If an item has a function attached, then that function is executed
-- before the key is returned.
--
local function show(m)
    while (true) do
        if m.title then
            print()
            print(BANNER)
            print(m.title)
            print(BANNER)
        end

        -- print the menu, one item per line
        for i=1,#m.items do
            printf("%2d) %s\n", i, m.items[i].description)
        end

        -- Read a number from the user
        printf("Menu choice: ")
        local c = io.read()
        if c then
            c = tonumber(c)
        end
        if not c then
            c = 999
        end

        -- Validate the user's choice
        if (c > 0) and (c <= #m.items) then
            local item = m.items[c]
            if item.func then
                local status, message = pcall(item.func, table.unpack(item.args))
                if status then
                    return item.key
                else
                    print()
                    print("ERROR: " .. message)
                end
            else
                return item.key
            end
        else
            printf("Invalid choice. Choose a number from %d to %d\n", 1, #m.items)
        end
    end
end

--
-- Create a fancier menu with an optional title. Returns a new menu.
-- Call m:item(m, key, description, func, ...) for each menu item.
-- Call m:show() to display the menu
--
function menu.new(title)
    local m = {}
    m.title = title
    m.items = {}
    m.item = set_item
    m.show = show
    return m
end

--
-- Show a simple menu and get the user's selection
--
function menu.show(choices)
    local m = menu.new()
    for i=1,#choices do
        m:item(i, choices[i])
    end
    return m:show()
end

--
-- Prompt the user for a string. Throw an error if the user aborts input.
--
function menu.prompt_string(prompt)
    printf("%s: ", prompt)
    local result = io.read("*l")
    if result == "" then
        error("User interrupted input")
    end
    return result
end

--
-- Prompt the user for a filename. Throw an error if the user aborts input.
--
function menu.prompt_filename(prompt)
    -- FIXME: Do tab completion of filenames
    return menu.prompt_string(prompt)
end

--
-- Prompt the user for a number. Throw an error if the user aborts input.
--
function menu.prompt_number(prompt)
    local result = menu.prompt_string(prompt)
    result = tonumber(result)
    if not result then
        error("Invalid number")
    end
    return result
end

--
-- Execute a Lua file, searching the Lua path as needed to find it
--
function menu.dofile(filename)
    local fullname = assert(package.searchpath(filename, package.path))
    dofile(fullname)
end
