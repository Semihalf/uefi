---
-- Module for creating menus and other user interface elements.
-- BDK applications generally use a console interface where interaction
-- with the user is performed. This module supplies building blocks for
-- a user interface based on text menus, data prompts, and interactive
-- command line editing.
--
-- * Written by Chad Reese
-- * Copyright (C) 2010-2012 Cavium Networks
--
require("strict")
require("utils")
local readline = require("readline")

menu = {}
menu.show_keys = false

-- Shown before and after menu titles
local BANNER = "================================="

--
-- Called when the user calls m:item()
-- Adds or updates a menu item.
-- @function menu:item
-- @param key object returned when the menu item is chosen
-- @param description Text shown to the user
-- @param func Optional function to call when the item is chosen
-- @param ... Optional arguments for the function
-- @return No return from this function
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

----
-- Called when the user calls m:show().
-- Shows a menu on the console. Returns the item key that is selected.
-- If an item has a function attached, then that function is executed
-- before the key is returned.
-- @function menu:show
--
local function show(m)
    -- Allow the user to do some menu specific customization. First argument
    -- is the menu, so the script can determine which menu it is called for.
    utils.run("autorun-menu", m)
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
                printf("%8s) %s\n", m.items[i].key, m.items[i].description)
            else
                printf("%2d) %s\n", i, m.items[i].description)
            end
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

---
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
-- Function for reading all menu prompts. This reads a word at a time
-- from the input. Lines with multiple words are returned across multiple
-- calls. As a special case an empty line is returned as is. Word based
-- input allows you to answer multiple prompts on one line, making line
-- editing more useful.
--
local pending_input = nil
local function read_input(prompt)
    local need_echo = true
    local word
    repeat
        if not pending_input then
            need_echo = false
            pending_input = readline.readline(prompt, nil, 0)
            if (pending_input == nil) or (pending_input == "") then
                pending_input = nil
                return ""
            end
        end
        word = pending_input:match("%s*%g+")
        if not word then
            pending_input = nil
        end
    until word
    pending_input = pending_input:sub(#word+1)
    word = word:match("%s*(%g+)")
    if need_echo then
        print(word)
    end
    return word
end

---
-- Prompt the user for a string. Throw an error if the user aborts input.
--
function menu.prompt_string(prompt, optional_default)
    local full_prompt
    if optional_default then
        full_prompt = "%s [%s]: " % {prompt, tostring(optional_default)}
    else
        full_prompt = "%s: " % prompt
    end
    local result = read_input(full_prompt)
    if result == "" then
        if optional_default then
            return optional_default
        end
        error("User interrupted input")
    end
    return result
end

---
-- Prompt the user for a filename. Throw an error if the user aborts input.
--
function menu.prompt_filename(prompt, optional_default)
    -- FIXME: Do tab completion of filenames
    return menu.prompt_string(prompt, optional_default)
end

---
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

---
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

---
-- Execute a Lua file, searching the Lua path as needed to find it
--
function menu.dofile(filename)
    local fullname = assert(package.searchpath(filename, package.path))
    return dofile(fullname)
end

return menu
