---
-- Simple utilities for Lua to do common operations.
-- * Written by Chad Reese
-- * Copyright (C) 2010-2011 Cavium Networks
-- * This module is released under the standard Lua MIT license
--

---
-- C style printf function. printf("format", ...).
--
function printf(...)
    io.write(string.format(...))
end

---
-- Python style string formatting
-- * str = "format" % value
-- * str = "format" % {...}
--
getmetatable("").__mod = function(format, param)
    if not param then
        return format
    elseif type(param) == "table" then
        return string.format(format, table.unpack(param))
    else
        return string.format(format, param)
    end
end

local function pprint_str(param, indent, visited)
    if type(param) == "nil" then
        return "nil"
    elseif type(param) == "boolean" then
        if param then
            return "true"
        else
            return "false"
        end
    elseif type(param) == "number" then
        return "%d (0x%x)" % {param, param}
    elseif type(param) == "string" then
        return "%q" % param
    elseif type(param) == "function" then
        return tostring(param)
    elseif type(param) == "userdata" then
        return tostring(param)
    elseif type(param) == "thread" then
        return "thread (%s)" % param:status()
    elseif type(param) == "table" then
        local keys = table.sorted_keys(param)
        visited[param] = 1
        local result = "{\n"
        for k=1, #keys do
            local table_indent = indent .. "    "
            local key = keys[k]
            local value = param[key]
            if (type(value) == "table") and visited[value] then
                if type(key) == "number" then
                    result = "%s%s[%d] = {...}\n" % {result, table_indent, key}
                else
                    result = "%s%s%s = {...}\n" % {result, table_indent, tostring(key)}
                end
            elseif type(key) == "number" then
                result = "%s%s[%d] = %s\n" % {result, table_indent, key, pprint_str(value, table_indent, visited)}
            else
                result = "%s%s%s = %s\n" % {result, table_indent, tostring(key), pprint_str(value, table_indent, visited)}
            end
        end
        return result .. indent .. "}"
    else
        error("Unsupported type %s" % type(param))
    end
end

---
-- Pretty print any Lua object
-- @param ... One or more Lua objects to display
--
function pprint(...)
    local p
    if rawget(table, "pack") == nil then
        p = {...}
        p.n = #p
    else
        p = table.pack(...)
    end
    local visited = {}
    local r = ""
    if p.n > 0 then
        r = pprint_str(p[1], "", visited)
        for i=2, p.n do
            r = "%s %s" % {r, pprint_str(p[i], "", visited)}
        end
    end
    print(r)
end

local function compare(a,b)
    local na = tonumber(a)
    local nb = tonumber(b)
    if na and nb then
        return na < nb
    else
        return tostring(a) < tostring(b)
    end
end

---
-- Return a table's keys in sorted order
-- @param tbl Table to sort keys of
-- @return Table of sorted keys
--
function table.sorted_keys(tbl)
    local result = {}
    for k,_ in pairs(tbl) do
        table.insert(result, k)
    end
    table.sort(result, compare)
    return result
end

---
-- Return a table's values in sorted order
-- @param tbl Table to sort values of
-- @return Table of sorted values
--
function table.sorted_values(tbl)
    local result = {}
    for _,v in pairs(tbl) do
        table.insert(result, v)
    end
    table.sort(result, compare)
    return result
end

---
-- Return if the string name is defiend as a global variable
-- @param name Name of a variable to check
--
function isglobal(name)
    return rawget(_G, name) ~= nil
end

---
-- Convert a string to hex
-- @function string:hex()
--
function string.hex(str)
    local hex = ""
    for i = 1,#str do
        hex = "%s%02x" % {hex, str:byte(i,i)}
    end
    return hex
end
