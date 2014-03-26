---
-- Lua module supporting DDR DRAM.
--
-- This module supplies an interface to OCTEON's DRAM controllers. The BDK
-- runs from L2 and doesn't initialize DRAM by default. The functions in
-- this module are used by the DDR menu to configure and initialize memory
-- on the fly. Once DRAM is initialized, the BDK heap is expanded to allow
-- access to all of DRAM.
--
-- * Written by Chad Reese
-- * Copyright (C) 2010-2013 Cavium Networks
--

require("strict")
require("utils")
require("fileio")

-- This is the table we use to contain the module
ddr = {}

-- local references to functions we need
local bdk_dram_config_raw = octeon.bdk_board_table_entry.bdk_dram_config_raw
local bdk_dram_lookup_board = octeon.bdk_board_table_entry.bdk_dram_lookup_board

--
-- SWIG structures are unusual as you need to iterate the metatable
-- to figure out what the members are.
--
local function dump_swig_object(object, prefix, file_handle)
    local getmetatable = getmetatable
    local type = type
    local tostring = tostring
    if octeon.global then
        getmetatable = octeon.global.getmetatable
        type = octeon.global.type
        tostring = octeon.global.tostring
    end
    local mt = object and getmetatable(object)
    if mt and mt[".get"] then
        prefix = prefix .. "."
        for _,k in ipairs(table.sorted_keys(mt[".get"])) do
            dump_swig_object(object[k], prefix .. k, file_handle)
        end
    else
        if object == nil then
            return file_handle:write("%s = nil\n" % prefix)
        elseif type(object) == "table" then
            for i=1,#object do
                local p = "%s[%d]" % {prefix, i}
                dump_swig_object(object[i], p, file_handle)
            end
        elseif type(object) == "number" then
            return file_handle:write("%s = 0x%x\n" % {prefix, object})
        elseif type(object) == "string" then
            file_handle:write("%s = \"" % prefix)
            for i=1,#object do
                file_handle:write("\\x%02x" % object:sub(i,i):byte())
            end
            file_handle:write("\"\n")
            return
        else
            return file_handle:write("%s = %s\n" % {prefix, tostring(object)})
        end
    end
end

---
-- Dump a board configuration in a human readable format
-- @param board_entry DRAM config structure
-- @param optional_filename Filename to write config to, or nil for stdout.
-- @return No return value, raises error on failure
--
function ddr.show_config(board_entry, optional_filename)
    assert(board_entry, "board_entry is nil")
    assert(type(board_entry) ~= "string", "board_entry is not a string")
    local handle = io.stdout
    if optional_filename then
        handle = fileio.open(optional_filename, "w")
    end
    dump_swig_object(board_entry, "  config", handle)
    if optional_filename then
        handle:close()
    end
end

---
-- Get the DRAM configuration for a given board name. If the
-- board name is nil, and empty swig object is returned
-- @param board_name String board name or nil
-- @return Returns DRAM configuration or raises an error
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
        -- provide an empty swig object
        return bdk_dram_lookup_board("")
    end
end

---
-- Given a board name or DRAM config structure, configure DRAM.
-- @param board_entry DRAM configuration of a string board name.
-- @param ddr_clock_hertz DRAM clock in Hertz.
-- @return Returns the amount of memory in megabytes or raises an error.
--
function ddr.set_config(board_entry, ddr_clock_hertz)
    -- A board name or structure is required
    assert(board_entry, "board_entry is nil")
    -- set default clock hertz if not provided
    ddr_clock_hertz = ddr_clock_hertz or 533000000

    if type(board_entry) == "string" then
        error("Invalid set_config arg: " .. board_entry)
        return
    end

    -- Configure DRAM
    local mbytes = bdk_dram_config_raw(board_entry, ddr_clock_hertz)
    if mbytes < 0 then
        error("DRAM configuration failed")
    end
    return mbytes
end

---
-- Test a region of memory for errors
-- @param start_address Physical address in memroy to start at
-- @param length Length of region to test
-- @return Returns nothing but raises an error on failure.
--
function ddr.test(start_address, length)
    local test_number = 0
    local errors = -1

    for test_number=0,20 do
        local name = octeon.c.bdk_dram_get_test_name(test_number);
        if not name then
            break
        end
        errors = octeon.c.bdk_dram_test(test_number, start_address, length)
        if errors ~= 0 then
            break
        end
    end

    if errors < 0 then
        error("DRAM test failed to run")
    elseif errors == 0 then
        print("All tests passed")
    else
        error("Test reported %d errors" % errors)
    end
end

---
-- Read a SPD from a DIMM
-- @param spd_addr TWSI address encoded as 256*bus+address
-- @return SPD string or throws an error
--
function ddr.read_spd(spd_addr)
    local node = spd_addr / 65536
    local twsi_bus = (spd_addr / 256) % 256
    local twsi_addr = spd_addr % 256
    local spd_len = octeon.c.bdk_twsix_read_ia(node, twsi_bus, twsi_addr, 0, 1, 1)
    assert(spd_len ~= -1, "TWSI read failed for SPD")
    spd_len = spd_len % 16
    local length
    if spd_len == 1 then
        length = 128
    elseif spd_len == 2 then
        length = 176
    elseif spd_len == 3 then
        length = 256
    else
        error("Invalid SPD length encoding")
    end
    local spd = {}
    for i=1,length do
        local v = octeon.c.bdk_twsix_read_ia(node, twsi_bus, twsi_addr, i-1, 1, 1)
        assert(v ~= -1, "TWSI read failed for SPD")
        spd[i] = string.char(v)
    end
    return table.concat(spd)
end

return ddr

