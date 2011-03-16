--
-- Lua module supporting DDR DRAM
-- Written by Chad Reese
-- Copyright (C) 2010-2011 Cavium Networks
--

require("strict")
require("utils")

-- This is the table we use to contain the module
ddr = {}

-- local references to functions we need
local bdk_dram_config = octeon.c.bdk_dram_config
local bdk_dram_test = octeon.c.bdk_dram_test
local bdk_dram_config_raw = bdk_board_table_entry.bdk_dram_config_raw
local bdk_dram_lookup_board = bdk_board_table_entry.bdk_dram_lookup_board

--
-- SWIG structures are unusual as you need to iterate the metatable
-- to figure out what the members are.
--
local function dump_swig_object(object, prefix)
    local mt = getmetatable(object)
    if mt and mt[".get"] then
        prefix = prefix .. "."
        for _,k in ipairs(table.sorted_keys(mt[".get"])) do
            dump_swig_object(object[k], prefix .. k)
        end
    else
        if type(object) == "table" then
            for i=1,#object do
                local p = "%s[%d]" % {prefix, i}
                dump_swig_object(object[i], p)
            end
        elseif type(object) == "number" then
            return printf("%s = 0x%x\n", prefix, object)
        else
            return printf("%s = %s\n", prefix, tostring(object))
        end
    end
end

--
-- Dump a board configuration in a human readable format
-- board_entry = DRAM config structure or board name
-- No return value, raises error on failure
--
function ddr.show_config(board_entry)
    if not board_entry then
        board_entry = ddr.get_config()
    elseif type(board_entry) == "string" then
        board_entry = ddr.get_config(board_entry)
    end
    dump_swig_object(board_entry, "    ")
end

--
-- Get the DRAM configuration for a given board name. If the
-- board name is nil, the current runnign configuration is returned.
-- board_name = Strign board name or nil
-- Returns DRAM configuration or raises an error
--
function ddr.get_config(board_name)
    if board_name then
        -- Lookup a board
        local result = bdk_dram_lookup_board(board_name)
        if not result then
            error("Invalid board name: " .. board_name)
        end
        return result
    else
        -- Lookup the current config
        return bdk_dram_lookup_board("")
    end
end

--
-- Given a board name or DRAM config structure, configure DRAM.
-- board_entry = DRMA configuration of a string board name
-- Returns the amount of memory in megabytes or raises an error
--
function ddr.set_config(board_entry)
    -- A board name or structure is required
    assert(board_entry)

    -- Fetch the board config if we were given a board name
    if type(board_entry) == "string" then
        board_entry = ddr.get_config(board_entry)
    end

    -- Configure DRAM
    local mbytes = bdk_dram_config_raw(board_entry)
    if mbytes < 0 then
        error("DRAM configuration failed")
    end
    return mbytes
end

--
-- Test a region of memory for errors
-- start_address = Physical address in memroy to start at
-- length = Length of region to test
-- Returns nothing but raises an error on failure.
--
function ddr.test(start_address, length)
    printf("Testing DRR from 0x%x to 0x%x with sequential write+read\n",
        start_address, start_address + length - 1)
    local errors = octeon.c.bdk_dram_test(0, start_address, length)

    if errors < 0 then
        error("DRAM test failed to run")
    elseif errors == 0 then
        print("Test passed")
    else
        error("Test reported %d errors" % errors)
    end

    printf("Testing DRR from 0x%x to 0x%x with random XOR\n",
        start_address, start_address + length - 1)
    errors = octeon.c.bdk_dram_test(1, start_address, length)

    if errors < 0 then
        error("DRAM test failed to run")
    elseif errors == 0 then
        print("Test passed")
    else
        error("Test reported %d errors" % errors)
    end
end

return ddr

