---
-- Access NOR flash connected to OCTEON's bootbus
--
-- * Written by Chad Reese
-- * Copyright (C) 2010-2013 Cavium Networks
require("strict")
require("utils")
require("fileio")
local bit64 = require("bit64")
local logging = require("logging")
local log = logging.new("NOR")
--local log = logging.new("NOR", logging.DEBUG)

local norflash = {}
local node = 0 -- octeon.MASTER_NODE
local init_complete = false
local READ_CSR
local WRITE_CSR
local CSR_TYPE_NCB
local MIO_BOOT_REG_CFGX

local oremote = require("oremote")
if oremote then
    -- Running remote, use oremote access functions
    READ_CSR = oremote.read_csr
    WRITE_CSR = oremote.write_csr
    CSR_TYPE_NCB = oremote.CSR_TYPE_NCB
    MIO_BOOT_REG_CFGX = oremote.csr.MIO_BOOT_REG_CFGX
else
    -- Running native, use C functions
    require("octeon")
    csr = octeon.csr
    READ_CSR = octeon.c.bdk_csr_read
    WRITE_CSR = octeon.c.bdk_csr_write
    CSR_TYPE_NCB = octeon.CSR_TYPE_NCB
    MIO_BOOT_REG_CFGX = octeon.csr.MIO_BOOT_REG_CFGX
end

--
-- Initialize the bootbus chip select regions
--
local function init_bootbus()
    -- We're going to assume that region 0 has a flash of up to 128MB. It is
    -- positioned such that it will alias the first 4MB to the normal MIPS
    -- boot address.
    for i=0,7 do
        local address = 0x0fc00000 + i * 0x20000000
        log:debug("Setting bootbus region %d to 0x%x size=%dMB\n", i, address, ((0xfff+1) * 64) / 1024)
        MIO_BOOT_REG_CFGX(i).BASE = address / 65536
        MIO_BOOT_REG_CFGX(i).SIZE = 0xfff
    end
end

--
-- Query the bootbus and determine the setup for a chip select
--
local function get_bootbus(chip_sel)
    local reg_cfg = MIO_BOOT_REG_CFGX(chip_sel).decode()
    if reg_cfg.EN == 0 then
        return nil
    end
    local result = {}
    result.chip_select = chip_sel
    result.orbit = reg_cfg.ORBIT
    result.ale = reg_cfg.ALE
    result.width = reg_cfg.WIDTH
    result.size = (reg_cfg.SIZE+1) * 0x10000
    result.base = reg_cfg.BASE * 0x10000
    return result
end

--
-- Perform a low level read with the given length and return the result as
-- an integer number. Length must be 1,2,4, or 8.
--
local function nor_read_num(nor, offset, length)
    local address = nor.bootbus.base + bit64.lshift(1, 48)
    address = address + offset
    local v = READ_CSR(node, CSR_TYPE_NCB, 0, length, address)
    log:debug("Read%d 0x%x: 0x%x\n", length*8, address, v)
    return v
end

--
-- Perform a low level write with the given length. Data is an integer
-- number. Length must be 1,2,4, or 8.
--
local function nor_write_num(nor, offset, length, data)
    local address = nor.bootbus.base + bit64.lshift(1, 48)
    address = address + offset
    log:debug("Write%d 0x%x: 0x%x\n", length*8, address, data)
    WRITE_CSR(node, CSR_TYPE_NCB, 0, length, address, data)
end

--
-- Read a series of bytes from NOR and return them as a string.
--
local function nor_read_str(nor, offset, length)
    local data = {}
    local i = 0
    while i<length do
        local size = 8
        while (size > length-i) or (bit64.band(offset, size-1) ~= 0) do
            size = bit64.rshift(size, 1)
        end
        local v = nor_read_num(nor, offset, size)
        while (size > 0) do
            i = i + 1
            size = size - 1
            data[i] = string.char(bit64.band(bit64.rshift(v, 8*size), 0xff))
            offset = offset + 1
        end
    end
    data = table.concat(data)
    return data
end

--
-- Write a series of bytes to NOR. This is does not program the bytes, it
-- just does the bootbus writes.
--
local function nor_write_str(nor, offset, data)
    local length = #data
    local i = 0
    while i<length do
        local size = 8
        while (size > length-i) or (bit64.band(offset, size-1) ~= 0) do
            size = bit64.rshift(size, 1)
        end
        local v = 0
        for j=1,size do
            i = i + 1
            v = v*256 + data:sub(i,i):byte()
        end
        nor_write_num(nor, offset, size, v)
        offset = offset + size
    end
end

--
-- Perform a CFI command read. CFI reads return a single byte
-- that will be repeated for wide reads.
--
local function nor_cmd_read(nor, offset)
    local length = 1
    if nor.cmd_16bit then
        -- Flash uses 16 bit commands
        length = 2
        offset = offset * 2
    end
    local result = nor_read_num(nor, offset, length)
    if length == 2 then
        local hi = bit64.rshift(result, 8)
        local lo = bit64.band(result, 0xff)
        if nor.bus_16bit then
            result = lo
        else
            assert(hi == lo, "Duplicate command bytes don't match")
            result = lo
        end
    end
    return result
end

--
-- Perform a CFI command write. CFI writes usa a single byte
-- that will be repeated for wide busses. This function wraps nor_write_num()
-- to create the duplicate bytes.
--
local function nor_cmd_write(nor, offset, value)
    if nor.bus_16bit then
        -- Flash uses 16 bit commands
        value = bit64.lshift(value, 8) + value
        offset = offset * 2
        nor_write_num(nor, offset, 2, value)
    elseif nor.cmd_16bit then
        -- Flash uses 16 bit commands, spaced every 2
        offset = offset * 2
        nor_write_num(nor, offset, 1, value)
    else
        -- Flash uses 8 bit commands
        nor_write_num(nor, offset, 1, value)
    end
end

--
-- Some CFI fields are two byte wide, stored in little endian order. This
-- wraps two calls nor_cmd_read() to get the full value.
--
local function nor_cmd_read16(nor, offset)
    if bit64.band(offset, 1) == 0 then
        if nor.bus_16bit or nor.cmd_16bit then
            offset = offset * 2
        end
        -- Read the value in one 16bit access
        return nor_read_num(nor, offset, 2)
    else
        local lo = nor_cmd_read(nor, offset)
        local hi = nor_cmd_read(nor, offset+1)
        return bit64.lshift(hi, 8) + lo
    end
end

--
-- Get the start of a block and its length for a given offset into NOR
--
local function nor_get_block(nor, offset)
    local address = 0
    for r=1, nor.params.regions do
        local region = nor.params.region[r]
        local region_size = region.num_blocks * region.block_size
        if (address <= offset) and (offset < address + region_size) then
            local block = (offset - address) / region.block_size
            return address + block * region.block_size, region.block_size
        end
    end
    return nil, "Offset not found in flash"
end

--- @class nor
-- Object returned by query()

--- NOR flash programming parameters.
-- Table containing information about the NOR chip.
-- @table nor:param

--- Reset NOR flash
-- @function nor:reset()

--- Erase a page in NOR flash
-- @function nor:erase(offset)
-- @param offset Location in flash to erase

--- Write data to flash
-- @function nor:write(offset, data)
-- @param offset Location in flash to write
-- @param data Data to write to flash

--- Erase and write to flash in a single step
-- @function nor:burn(offset, data, show_status)
-- @param offset Location in flash to burn
-- @param data Data to write to flash
-- @param show_status Set to true to see progress during burn

--- Read bytes from flash
-- @function nor:read(offset, length)
-- @param offset Location in flash to read
-- @param length Number of bytes to read
-- @return Data bytes as a string

--
-- Erase and write to flash in a single step
--
local function nor_burn(nor, offset, data, show_status)
    if show_status then
        printf("  0%%")
    end
    local loc = 1
    while loc < #data do
        if show_status then
            local percent = 100 * loc / #data
            printf("\b\b\b\b%3d%%", percent)
            io.flush()
        end
        local block_begin, block_size = assert(nor_get_block(nor, offset))
        assert(block_begin == offset, "Burn must start on a block boundary")
        nor:erase(offset)
        nor:write(offset, data:sub(loc, loc + block_size - 1))
        offset = offset + block_size
        loc = loc + block_size
    end
    if show_status then
        printf("\b\b\b\b100%%\n")
    end
end

--
-- AMD based command set - Reset flash
-- Note: The EBB6300 and EBB6800 have AMD based parts
--
local function amd_reset(nor)
    log:debug("[AMD] Reset\n")
    nor_cmd_write(nor, 0x555, 0xaa) -- Unlock start
    nor_cmd_write(nor, 0x2aa, 0x55) -- Unlock ack
    nor_cmd_write(nor, 0, 0xf0) -- Reset
end

--
-- AMD based command set - Erase block
--
local function amd_erase(nor, offset)
    nor:reset(nor)
    log:debug("[AMD] Erase\n")
    -- Send the erase sector command sequence
    nor_cmd_write(nor, 0x555, 0xaa) -- Unlock start
    nor_cmd_write(nor, 0x2aa, 0x55) -- Unlock ack
    nor_cmd_write(nor, 0x555, 0x80) -- Erase start
    nor_cmd_write(nor, 0x555, 0xaa) -- Unlock start
    nor_cmd_write(nor, 0x2aa, 0x55) -- Unlock ack
    if nor.bus_16bit then
        nor_write_num(nor, offset, 2, 0x3030) -- Erase sector
    else
        nor_write_num(nor, offset, 1, 0x30) -- Erase sector
    end

    -- Loop checking status
    local timeout = os.time() + 1
    while nor_read_num(nor, offset, 1) ~= 0xff do
        assert(os.time() <= timeout, "NOR: Timeout erasing block")
    end
    nor:reset(nor)
end

--
-- AMD based command set - Write block
--
local function amd_write(nor, offset, data)
    nor:reset(nor)
    -- Loop through one byte at a time
    while #data > 0 do
        local write_len = 1
        if nor.bus_16bit then
            write_len = 2
        end
        local to_write = data:sub(1,write_len)
        data = data:sub(write_len+1)
        -- Send the program sequence
        log:debug("[AMD] Write\n")
        nor_cmd_write(nor, 0x555, 0xaa) -- Unlock start
        nor_cmd_write(nor, 0x2aa, 0x55) -- Unlock ack
        nor_cmd_write(nor, 0x555, 0xa0) -- Write
        nor_write_str(nor, offset, to_write)

        -- Loop polling for status
        local timeout = os.time() + 1
        while nor_read_str(nor, offset, write_len) ~= to_write do
            assert(os.time() <= timeout, "NOR: Timeout writing block")
        end
        -- Increment to the next byte
        offset = offset + write_len
    end
    nor:reset()
end

--
-- AMD based command set - Write block buffered
--
local function amd_write_buffered(nor, offset, data)
    -- Make sure the write data has an even length. This is
    -- needed for 16bit accesses to flash
    if bit64.band(#data, 1) == 1 then
        data = data .. "\xff"
    end
    nor:reset(nor)
    -- Loop until no more data
    while #data > 0 do
        local write_len = nor.params.max_write
        if write_len > #data then
            write_len = #data
        end
        local to_write = data:sub(1,write_len)
        data = data:sub(write_len+1)
        -- Send the program sequence
        log:debug("[AMD] Write Buffered\n")
        nor_cmd_write(nor, 0x555, 0xaa) -- Unlock start
        nor_cmd_write(nor, 0x2aa, 0x55) -- Unlock ack
        nor_write_num(nor, offset, 2, 0x2525) -- Write buffered
        if nor.bus_16bit then
            nor_write_num(nor, offset, 2, write_len/2-1) -- Write length
        else
            nor_write_num(nor, offset, 2, write_len-1) -- Write length
        end
        -- Write the data to the buffer
        nor_write_str(nor, offset, to_write)
        -- Check that the buffer received the data
        assert(nor_read_num(nor, offset, 1) == 0, "NOR: Write to buffer failed")
        -- Confirm the write
        nor_write_num(nor, offset, 2, 0x2929) -- Write confirm

        -- Loop polling for status
        local correct = to_write:sub(1,8)
        local timeout = os.time() + 1
        while nor_read_str(nor, offset, 8) ~= correct do
            assert(os.time() <= timeout, "NOR: Timeout writing block")
        end
        -- Increment to the next byte
        offset = offset + write_len
    end
    nor:reset()
end

--
-- Intel based command set - Reset flash
-- Note: The NIC10E has an Intel based part
--
local function intel_reset(nor)
    log:debug("[Intel] Reset\n")
    nor_cmd_write(nor, 0, 0xff)
end

--
-- Poll status byte on Intel based chips
--
local function intel_poll_status(nor, offset, message)
    message = "NOR: Timeout %s" % message
    local status
    local timeout = os.time() + 1
    repeat
        assert(os.time() <= timeout, message)
        status = nor_read_num(nor, offset, 1)
    until bit64.btest(status, 0x80)
    return status
end

--
-- Intel based command set - Erase block
--
local function intel_erase(nor, offset)
    nor:reset(nor)
    log:debug("[Intel] Erase\n")
    -- Clear lock bits
    nor_write_num(nor, offset, 1, 0x60)
    nor_write_num(nor, offset, 1, 0xd0)
    intel_poll_status(nor, offset, "clear locks")
    -- Send the erase sector command sequence
    nor_write_num(nor, offset, 1, 0x20)
    nor_write_num(nor, offset, 1, 0xd0)
    intel_poll_status(nor, offset, "erase block")
    nor:reset(nor)
end

--
-- Intel based command set - Write block
--
local function intel_write(nor, offset, data)
    nor:reset(nor)
    log:debug("[Intel] Write\n")
    -- Loop through one byte at a time
    for i=1, #data do
        local to_write = data:sub(i,i):byte()
        local off = offset + i - 1
        -- Send the program sequence
        nor_write_num(nor, off, 1, 0x40)
        nor_write_num(nor, off, 1, to_write);
        intel_poll_status(nor, off, "write")
    end
    nor:reset(nor)
end

--
-- Perform a CFI query and determine what type of NOR flash is connected
--
local function cfi_query(chip_sel)
    local nor = {}
    nor.bootbus = get_bootbus(chip_sel)
    if not nor.bootbus then
        return nil
    end
    nor.cmd_16bit = true
    nor.bus_16bit = (nor.bootbus.width == 1)
    -- Dummy read to make sure flash is in the normal access mode
    nor_read_num(nor, 0, 1)
    -- Send reset command for both AMD and Intel command sets
    amd_reset(nor)
    intel_reset(nor)
    log:debug("CFI Query\n")
    -- Send the query command
    nor_cmd_write(nor, 0x55, 0x98)
    -- Read CFI query identification string
    local result = nor_cmd_read(nor, 0x10)
    assert(result == 0x51, "Expected 'Q' from CFI query")
    local result = nor_cmd_read(nor, 0x11)
    assert(result == 0x52, "Expected 'R' from CFI query")
    local result = nor_cmd_read(nor, 0x12)
    assert(result == 0x59, "Expected 'Y' from CFI query")
    log:debug("Reading CFI parameters\n")
    nor.params = {}
    nor.params.primary_cmd_set = nor_cmd_read16(nor, 0x13)
    nor.params.primary_extend = nor_cmd_read16(nor, 0x15)
    nor.params.alternate_cmd_set = nor_cmd_read16(nor, 0x17)
    nor.params.alternate_extend = nor_cmd_read16(nor, 0x19)
    -- Read CFI query system interface information
    nor.params.vcc_logic_min = nor_cmd_read(nor, 0x1b)
    nor.params.vcc_logic_max = nor_cmd_read(nor, 0x1c)
    nor.params.vcc_program_min = nor_cmd_read(nor, 0x1d)
    nor.params.vcc_program_max = nor_cmd_read(nor, 0x1e)
    nor.params.typical_write_timeout = nor_cmd_read(nor, 0x1f)
    nor.params.typical_write = nor_cmd_read(nor, 0x20)
    nor.params.typical_erase_timeout = nor_cmd_read(nor, 0x21)
    nor.params.typical_erase_full = nor_cmd_read(nor, 0x22)
    nor.params.max_write_timeout = nor_cmd_read(nor, 0x23)
    nor.params.max_buffer_timeout = nor_cmd_read(nor, 0x24)
    nor.params.max_erase_timeout = nor_cmd_read(nor, 0x25)
    nor.params.max_erase_full = nor_cmd_read(nor, 0x26)
    -- Read Device Geometry
    nor.params.size = bit64.lshift(1, nor_cmd_read(nor, 0x27))
    nor.params.interface_description = nor_cmd_read16(nor, 0x28)
    nor.params.max_write = bit64.lshift(1, nor_cmd_read16(nor, 0x2a))
    nor.params.regions = nor_cmd_read(nor, 0x2c)
    nor.params.region = {}
    for r=1, nor.params.regions do
        local region = {}
        region.num_blocks = nor_cmd_read16(nor, 0x2d + (r-1) * 4) + 1
        region.block_size = nor_cmd_read16(nor, 0x2f + (r-1) * 4)
        if region.block_size == 0 then
            region.block_size = 128
        else
            region.block_size = region.block_size * 256
        end
        nor.params.region[r] = region
    end
    local reversed = nor_cmd_read(nor, nor.params.primary_extend + 0xf)
    if bit64.btest(reversed, 1) then
        local r = {}
        for i=1, nor.params.regions do
            r[i] = nor.params.region[nor.params.regions - i + 1]
        end
        nor.params.region = r
    end
    if (nor.params.primary_cmd_set == 0x0001) or
       (nor.params.primary_cmd_set == 0x0003) then
        -- intel based command set
        log:info("Using Intel command set\n")
        nor.reset = intel_reset
        nor.erase = intel_erase
        nor.write = intel_write
    elseif (nor.params.primary_cmd_set == 0x0002) or
           (nor.params.primary_cmd_set == 0x0004) then
        -- amd based command set
        log:info("Using AMD command set\n")
        nor.reset = amd_reset
        nor.erase = amd_erase
        if nor.params.max_write > 2 then
            nor.write = amd_write_buffered
        else
            nor.write = amd_write
        end
    else
        error("NOR: Unknown command set")
    end

    nor.burn = nor_burn
    function nor:read(offset, length)
        return nor_read_str(nor, offset, length)
    end
    nor:reset()
    log:info("Flash info for chip select %d = \n", chip_sel)
    log:info(nor)
    return nor
end

---
-- This query function is the only module level function exposed. Call
-- it to get the NOR object instance.
-- @param chip_sel OCTEON bootbus chip select the NOR flash is connected to.
-- @return Object of class "nor" representing the NOR flash.
--
function norflash.query(chip_sel)
    if not init_complete then
        init_bootbus()
        init_complete = true
    end
    return assert(cfi_query(chip_sel), "CFI Query failed")
end

return norflash
