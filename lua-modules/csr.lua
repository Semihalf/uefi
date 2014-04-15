--- Pure Lua implementation of OCTEON CSR access by name.
-- This module creates a "csr" table that contains names for each CSR
-- supported by the OCTEON chip. CSRs can then be accessed with code
-- using names and field names.
--
-- * value = X.csr.NAME.read()
-- * X.csr.NAME.write(value)
-- * X.csr.NAME.display()
-- * value = X.csr.NAME.FIELD
-- * X.csr.NAME.FIELD = value
-- * tbl = X.csr.NAME.decode()
-- * X.csr.NAME.encode(tbl)
--
-- Note: This module should not be used directly. It is used by the modules
-- "octeon" and "oremote" to generate the CSR access "octeon.csr.*" and
-- "oremote.csr.*".
--
-- * Written by Chad Reese
-- * Copyright (C) 2010-2013 Cavium Networks
--

require("strict")
require("utils")
require("menu")
local bit64 = require("bit64")

---
-- Create an instance of a CSR object that can perform operations on a CSR.
-- Instances are created once the full address information is resolved.
--
local function csr_instance(node, csr_name, csr_type, busnum, csr_size, address, fields, read_func, write_func)
    local csr = {}

    ---
    -- Read a CSR and return its value
    --
    function csr.read()
        return read_func(node, csr_type, busnum, csr_size, address)
    end

    ---
    -- Write a value to a CSR
    --
    function csr.write(value)
        write_func(node, csr_type, busnum, csr_size, address, value)
    end

    ---
    -- Display a CSR value in a pretty format
    --
    function csr.display(optional_value)
        -- Do a read if a value wasn't supplied to display
        local value = optional_value or csr.read()
        printf("%s[0x%016x] = 0x%016x\n", csr_name, address, value)
        -- Iterate fields starting at the high bit and working down
        for i = 1,#fields do
            local f = fields[i]
            local v = bit64.bextract(value, f.start, f.stop)
            if f.start == f.stop then
                printf("  [   %2d] %-20s = %10d (0x%x)\n", f.start, f.name, v, v)
            else
                printf("  [%2d:%2d] %-20s = %10d (0x%x)\n", f.stop, f.start, f.name, v, v)
            end
        end
    end

    ---
    -- Decode a CSR into a table of fields
    --
    function csr.decode(optional_value)
        -- Do a read if a value wasn't supplied to decode
        local value = optional_value or csr.read()
        local t = {}
        for _,f in pairs(fields) do
            t[f.name] = bit64.bextract(value, f.start, f.stop)
        end
        return t
    end

    ---
    -- Update a CSR based on a table of fields
    --
    function csr.encode(new_values)
        -- Read the current CSR value
        local value = csr.read()
        -- Update with all the fields specified
        for n,v in pairs(new_values) do
            local found = false
            for _,f in pairs(fields) do
                if n == f.name then
                    value = bit64.binsert(value, v, f.start, f.stop)
                    found = true
                    break
                end
            end
            assert(found, "Illegal CSR field %s.%s" % {csr_name, n})
        end
        -- Write the new value
        csr.write(value)
    end

    -- Install the meta table to support field access
    local meta = {}
    setmetatable(csr, meta)

    --
    -- Automatically read and decode a CSR if someone attempts to
    -- read a field.
    --
    function meta.__index(unused, field_name)
        for _,f in pairs(fields) do
            if f.name == field_name then
                return bit64.bextract(csr.read(), f.start, f.stop)
            end
        end
        error("Illegal CSR field %s.%s" % {csr_name, field_name})
    end

    --
    -- Automatically do a read, modify, and write if someone attempts to
    -- write a field.
    --
    function meta.__newindex(unused, field_name, value)
        for _,f in pairs(fields) do
            if field_name == f.name then
                return csr.write(bit64.binsert(csr.read(), value, f.start, f.stop))
            end
        end
        error("Illegal CSR field %s.%s" % {csr_name, field_name})
    end

    return csr
end

--
-- Called to perform range checking on CSR function parameters
--
local function check_range(value, range)
    for r = 1, #range, 2 do
        if (range[r] <= value) and (value <= range[r+1]) then
            return
        end
    end
    error("Parameter out of range")
end

--
-- This function either creates a instance of a CSR object or creates a
-- function that returns the CSR object once the proper parameters are
-- present.
--
local function create_csr(node, csr_name, csr_type, csr_size, base_address, params,
    fields, read_func, write_func)
    local num_params = #params / 2
    if num_params == 0 then
        return csr_instance(node, csr_name, csr_type, 0, csr_size, base_address, fields, read_func, write_func)
    else
        return function (...)
            local args = table.pack(...)
            local address = base_address
            local name = csr_name
            if #args ~= num_params then
                error("CSR %s requires %d parameters" % {name, num_params})
            end
            for i=1,num_params do
                check_range(args[i], params[i*2-1])
                address = address + args[i] * params[i*2]
                if i == 1 then
                    name = "(%d" % args[i]
                else
                    name = ",%d" % args[i]
                end
            end
            if num_params > 0 then
                name = name .. ")"
            end
            local busnum = 0
            if num_params > 0 then
                busnum = args[1]
            end
            return csr_instance(node, name, csr_type, busnum, csr_size, address, fields, read_func, write_func)
        end
    end
end

--
-- Given a list of CSRs for this chip, build a csr table for use by
-- oremote.csr.
--
local function build_table(chip_csr, container, read_func, write_func)
    local csr_table = {}
    local node = 0 -- octeon.MASTER_NODE
    for n,c in pairs(chip_csr) do
        -- Determine if this CSR needs parameters
        local params = {}
        local i = 0
        while true do
            local key = "range" .. (i+1)
            if c[key] then
                table.insert(params, c[key])
                table.insert(params, c[key .. "_inc"])
                i = i + 1
            else
                break
            end
        end
        -- Convert the CSR type from a string into a number
        local csr_type = container["CSR_TYPE_" .. c.type]
        assert(csr_type, "Illegal CSR type " .. c.type)
        -- Create the CSR table entry
        csr_table[n] = create_csr(node, n, csr_type, c.width, c.address, params,
            c.fields, read_func, write_func)
    end

    --
    -- Lookup a CSR by name
    --
    function csr_table.lookup(csr_str)
        csr_str = csr_str:upper()
        local p = csr_str:find("%(")
        if p then
            local c = csr_str:find(",")
            if c then
                local name, arg1, arg2 = csr_str:match("^([%w_]+)%((%d+),(%d+)%)$")
                assert(name and arg1 and arg2, "Illegally formatted CSR name")
                local csr = assert(csr_table[name], "CSR not found")
                return csr(tonumber(arg1), tonumber(arg2))
            else
                local name, arg = csr_str:match("^([%w_]+)%((%d+)%)$")
                assert(name and arg, "Illegally formatted CSR name")
                local csr = assert(csr_table[name], "CSR not found")
                return csr(tonumber(arg))
            end
        else
            local csr = csr_table[csr_str]
            if csr then
                assert(type(csr) ~= "function", "CSR requires arguments")
                return csr
            end
            -- If we can't find a CSR, try looking for the version where
            -- the parameters are encoded into the name
            -- We search the chip_csr data so we get the names with "#"
            -- in the location a parameter should be
            for name,csr_data in pairs(chip_csr) do
                -- Check that the CSR needs arguments so we can avoid
                -- slow pattern matches on stuff that won't match
                csr = csr_table[name]
                if type(csr) == "function" then
                    -- Change the "#" into "([0-9]+)" so we get the numeric
                    -- parameters as the match. Add "^" and "$" to force a
                    -- full match
                    local pattern = "^" .. chip_csr[name].name:gsub("#", "([0-9]+)") .. "$"
                    local arg1, arg2 = csr_str:match(pattern)
                    if arg2 then
                        -- The arguments are swapped here as the functions
                        -- expect (offset, block), but the number
                        -- substitution gets (block, offset)
                        return csr(tonumber(arg2), tonumber(arg1))
                    elseif arg1 then
                        -- One argument match
                        return csr(tonumber(arg1))
                    end
                end
            end
            -- Loop found no matches, so fail
            error("CSR not found")
        end
    end

    -- Install the meta table to support call access to names
    local meta = {}
    setmetatable(csr_table, meta)

    function meta.__call(self)
        local names = {}
        for n in pairs(self) do
            table.insert(names, n)
        end
        names = table.sorted_values(names)
        local function next_name(names, previous_name)
            local r = names[1]
            table.remove(names, 1)
            return r
        end
        return next_name, names, nil
    end

    return csr_table
end

--
-- Find which chip we are using and build a csr table for it
--
local function lookup_chip(container, read_func, write_func)
    local csr_db = menu.dofile("csr_db")
    for n,v in pairs(csr_db) do
        if container.is_model(container[n]) then
            return build_table(v, container, read_func, write_func)
        end
    end
    print("WARNING: Chip not found on CSR database, defaulting to CN70XX")
    return build_table(csr_db["CN70XX"], container, read_func, write_func)
end

return lookup_chip
