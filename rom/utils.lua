--
-- Simple utilities for Lua to do common operations
-- Written by Chad Reese
-- Copyright (C) 2010-2011 Cavium Networks
-- This module is released under the standard Lua MIT license
--

require("strict")

--
-- C Stype printf function. printf("format", ...).
--
function printf(...)
    io.write(string.format(...))
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

--
-- Return a table's keys in sorted order
--
function table.sorted_keys(tbl)
    local result = {}
    for k,_ in pairs(tbl) do
        table.insert(result, k)
    end
    table.sort(result)
    return result
end

--
-- Return a table's values in sorted order
--
function table.sorted_values(tbl)
    local result = {}
    for _,v in pairs(tbl) do
        table.insert(result, v)
    end
    table.sort(result)
    return result
end


--
-- Hex dump a file. "f" is a file handle, not a name. You can do a seek
-- before calling this to skip the start of the file
--
function hexdump(f)
    local loc = f:seek("cur")
    local last_data
    local repeat_count = 0
    local data = f:read(16)
    while data do
        if data == last_data then
            repeat_count = repeat_count + 1
            if repeat_count == 1 then
                printf("*\n")
            end
        else
            repeat_count = 0;
            last_data = data
            printf("%08x: ", loc)
            for i=1,#data do
                printf("%02x", data:byte(i))
                if (i%4 == 0) then
                    printf(" ")
                end
            end
            if #data < 16 then
                for i=#data+1,16 do
                    printf("  ")
                    if (i%4 == 0) then
                        printf(" ")
                    end
                end
            end
            printf("   ")
            for i=1,#data do
                local c = data:byte(i)
                if (c < 32) or (c > 127) then
                    printf(".")
                else
                    printf("%s", data:sub(i,i))
                end
            end
            printf("\n")
        end
        data = f:read(16)
        loc = loc + 16
    end
end


--
-- Needed for compatibility with Lua 5.1
--
if rawget(table, "unpack") == nil then
    table.unpack = unpack
end
