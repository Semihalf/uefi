require("strict")
require("utils")

menu = {}
menu.show_keys = false

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
            if menu.show_keys then
                printf("%-8s ", m.items[i].key)
            end
            printf("%2d) %s\n", i, m.items[i].description)
        end

        -- Read a number from the user
        local c = 999
        local response = menu.prompt_string("Menu choice", "")
        if response then
            if response == "keys" then
                menu.show_keys = not menu.show_keys
            elseif tonumber(response) then
                c = tonumber(response)
            else
                for i = 1,#m.items do
                    if m.items[i].key == response then
                        c = i
                        break
                    end
                end
            end
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
-- Prompt the user for a string. Throw an error if the user aborts input.
--
function menu.prompt_string(prompt, optional_default)
    if optional_default then
        printf("%s [%s]: ", prompt, tostring(optional_default))
    else
        printf("%s: ", prompt)
    end
    local result = io.read("*l")
    if result == "" then
        if optional_default then
            return optional_default
        end
        error("User interrupted input")
    end
    return result
end

--
-- Prompt the user for a filename. Throw an error if the user aborts input.
--
function menu.prompt_filename(prompt, optional_default)
    -- FIXME: Do tab completion of filenames
    return menu.prompt_string(prompt, optional_default)
end

--
-- Prompt the user for a number. Throw an error if the user aborts input.
--
function menu.prompt_number(prompt, optional_default, optional_min, optional_max)
    if optional_min then
        if optional_max then
            prompt = prompt .. " (" .. tostring(optional_min) .. " - " .. tostring(optional_max) .. ")"
        else
            prompt = prompt .. " (min " .. tostring(optional_min) .. ")"
        end
    elseif optional_max then
        prompt = prompt .. " (max " .. tostring(optional_max) .. ")"
    end
    local result = menu.prompt_string(prompt, optional_default)
    result = tonumber(result)
    if not result then
        error("Invalid number")
    end
    if optional_min and (result < optional_min) then
        error("Out of range")
    end
    if optional_max and (result > optional_max) then
        error("Out of range")
    end
    return result
end

--
-- Prompt the user for a yes or no question(y/n). Throw an error if the
-- user aborts input. Output is true or false
--
function menu.prompt_yes_no(prompt, optional_default)
    local result = menu.prompt_string(prompt .. "(y/n)", optional_default)
    if result == "y" then
        return true
    elseif result == "n" then
        return false
    else
        error("Invalid input, expected \"y\" or \"n\"")
    end
end

--
-- Execute a Lua file, searching the Lua path as needed to find it
--
function menu.dofile(filename)
    local fullname = assert(package.searchpath(filename, package.path))
    dofile(fullname)
end
