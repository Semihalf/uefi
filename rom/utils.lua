--
-- Simple utilities for Lua to do common operations
-- Written by Chad Reese
-- Copyright (C) 2010-2011 Cavium Networks
-- This module is released under the standard Lua MIT license
--

-- require("strict")

--
-- C Stype printf function. printf("format", ...).
--
function printf(...)
    print(string.format(...))
end

--
-- Python style string formatting
-- str = "format" % value
-- str = "format" % {...}
--
getmetatable("").__mod = function(format, param)
    if not param then
        return format
    elseif type(param) == "table" then
        return string.format(format, unpack(param))
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
        return "%d" % param
    elseif type(param) == "string" then
        return "%q" % param
    elseif type(param) == "function" then
        return "function"
    elseif type(param) == "userdata" then
        return "userdata"
    elseif type(param) == "thread" then
        return "thread (%s)" % param:status()
    elseif type(param) == "table" then
        local count = 0
        local keys = {}
        for k in pairs(param) do
            count = count + 1
            keys[count] = k
        end
        table.sort(keys)
        visited[param] = 1
        local result = "{\n"
        for k=1, count do
            local table_indent = indent .. "    "
            local key = keys[k]
            local value = param[key]
            if (type(value) == "table") and visited[value] then
                result = "%s%s%s = {...}\n" % {result, table_indent, key}
            elseif type(key) == "number" then
                result = "%s%s[%d] = %s\n" % {result, table_indent, key, pprint_str(value, table_indent, visited)}
            else
                result = "%s%s%s = %s\n" % {result, table_indent, key, pprint_str(value, table_indent, visited)}
            end
        end
        return result .. indent .. "}"
    else
        error("Unsupported type %s" % type(param))
    end
end

--
-- Pretty print
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
