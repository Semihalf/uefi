require("strict")
require("utils")
local bit64 = require("bit64")
local csr_db = require("csr_db")
local oremote = require("oremote")
local cnx = oremote

--
-- Create an instance of a CSR object that can perform operations on a CSR.
-- Instances are created once the full address information is resolved.
--
local function csr_instance(csr_name, csr_type, busnum, csr_size, address, fields)
    local csr = {}

    --
    -- Read a CSR and return its value
    --
    function csr.read()
        return cnx.read_csr_raw(csr_type, busnum, csr_size, address)
    end

    --
    -- Write a value to a CSR
    --
    function csr.write(value)
        cnx.write_csr_raw(csr_type, busnum, csr_size, address, value)
    end

    --
    -- Display a CSR value in a pretty format
    --
    function csr.display(optional_value)
        -- Do a read if a value wasn't supplied to display
        local value = optional_value or csr.read()
        printf("%s[0x%016x] = 0x%016x\n", csr_name, address, value)
        -- Iterate fields starting at the high bit and working down
        for i = #fields,1,-1 do
            local f = fields[i]
            local v = bit64.bextract(value, f.start, f.stop)
            if f.start == f.stop then
                printf("  [   %2d] %-20s = %10d (0x%x)\n", f.start, f.name, v, v)
            else
                printf("  [%2d:%2d] %-20s = %10d (0x%x)\n", f.stop, f.start, f.name, v, v)
            end
        end
    end

    --
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

    --
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
            assert(found, "Illegal CSR field")
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
        local t = csr.decode()
        assert(t[field_name], "Illegal CSR field")
        return t[field_name]
    end

    --
    -- Automatically do a read, modify, and write if someone attempts to
    -- write a field.
    --
    function meta.__newindex(unused, field_name, value)
        local t = csr.decode(0)
        assert(t[field_name], "Illegal CSR field")
        t[field_name] = value
        csr.encode(t)
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
-- function that returns teh CSR object once the proper parameters are
-- present.
--
local function create_csr(csr_name, csr_type, csr_size, num_params, base_address,
    range1, increment1, range2, increment2, fields)
    if num_params == 0 then
        return csr_instance(csr_name, csr_type, 0, csr_size, base_address, fields)
    elseif num_params == 1 then
        return function (index)
            check_range(index, range1)
            local address = base_address + index * increment1
            local name = "%s(%d)" % {csr_name, index}
            return csr_instance(name, csr_type, index, csr_size, address, fields)
        end
    elseif num_params == 2 then
        return function (index, block)
            check_range(index, range1)
            check_range(block, range2)
            local address = base_address + index * increment1 + block * increment2
            local name = "%s(%d,%d)" % {csr_name, index, block}
            return csr_instance(name, csr_type, block, csr_size, address, fields)
        end
    else
        error("Invalid number of parameters for a CSR")
    end
end

--
-- Given a list of CSRs for this chip, build a csr table for use by
-- oremote.csr.
--
local function build_table(chip_csr)
    local csr_table = {}
    for n,c in pairs(chip_csr) do
        -- Determine if this CSR needs parameters
        local params = 0
        if c.range2 then
            params = 2
        elseif c.range1 then
            params = 1
        end
        -- Convert the CSR type from a string into a number
        local csr_type = cnx["CSR_TYPE_" .. c.type]
        assert(csr_type, "Illegal CSR type " .. c.type)
        -- Create the CSR table entry
        csr_table[n] = create_csr(n, csr_type, c.width, params, c.address,
            c.range1, c.range1_inc, c.range2, c.range2_inc, c.fields)
    end
    return csr_table
end

--
-- Find which chip we are using and build a csr table for it
--
local function lookup_chip()
    for n,v in pairs(csr_db) do
        if cnx.is_model(cnx[n]) then
            return build_table(v)
        end
    end
    error("Chip not found on CSR database")
end

return lookup_chip()
