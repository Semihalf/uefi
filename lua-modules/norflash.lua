require("strict")
require("utils")
require("fileio")
local bit64 = require("bit64")
local logging = require("logging")
local log = logging.new("NOR")

local norflash = {}
local use_oremote = true
local init_complete = false

local oremote
local csr
if use_oremote then
    oremote = require("oremote")
    csr = oremote.csr
else
    require("octeon")
    csr = octeon.csr
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
        log:debug("Setting bootbus region %d to 0x%x size=256MB\n", i, address)
        csr.MIO_BOOT_REG_CFGX(i).BASE = address / 65536
        csr.MIO_BOOT_REG_CFGX(i).SIZE = 0xfff
    end
end

--
-- Query the bootbus and determine the setup for a chip select
--
local function get_bootbus(chip_sel)
    local reg_cfg = csr.MIO_BOOT_REG_CFGX(chip_sel).decode()
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
-- Perform a low level read to a bootbus chip select
--
local function nor_read(bootbus_info, offset, length)
    local address = bootbus_info.base
    address = address + offset
    address = address + bit64.lshift(1, 48)
    local data
    if use_oremote then
        data = {}
        for i=1,length do
            local v = oremote.read_csr_raw(oremote.CSR_TYPE_NCB, 0, 1, address+i-1)
            data[i] = string.char(v)
        end
        data = table.concat(data)
    else
        local f = fileio.open("/dev/mem", "r", address)
        f:setvbuf("full", length)
        data = f:read(length)
        f:close()
    end
    log:debug("Read 0x%x len=%d: %s\n", address, length, data:hex())
    return data
end

--
-- Perform a low level write to a bootbus chip select
--
local function nor_write(bootbus_info, offset, data)
    local address = bootbus_info.base
    address = address + offset
    address = address + bit64.lshift(1, 48)
    log:debug("Write 0x%x len=%d: %s\n", address, #data, data:hex())

    if use_oremote then
        for i=1,#data do
            local v = data:sub(i,i):byte()
            oremote.write_csr_raw(oremote.CSR_TYPE_NCB, 0, 1, address, v)
            address = address + 1
        end
    else
        local f = fileio.open("/dev/mem", "w", address)
        f:setvbuf("full", #data)
        f:write(data)
        f:close()
    end
end

--
-- Perform a CFI command read. CFI reads return a single byte
-- that will be repeated for wide reads. This function wraps nor_read()
-- and verifies that the duplicate bytes are correct.
--
local function nor_cmd_read(nor, offset)
    local length = 1
    if nor.cmd_16bit then
        -- Flash uses 16 bit commands
        length = 2
        offset = offset * 2
    end
    local result = nor_read(nor.bootbus, offset, length)
    if length == 2 then
        assert(result:sub(1,1) == result:sub(2,2), "Duplicate command bytes don't match")
        result = result:sub(1,1)
    end
    -- Convert the byte to a number
    return result:byte(1)
end

--
-- Perform a CFI command write. CFI writes usa a single byte
-- that will be repeated for wide busses. This function wraps nor_write()
-- to create the duplicate bytes.
--
local function nor_cmd_write(nor, offset, value)
    local data = string.char(value)
    if nor.cmd_16bit then
        -- Flash uses 16 bit commands
        offset = offset * 2
    end
    nor_write(nor.bootbus, offset, data)
end

--
-- Some CFI fields are two byte wide, stored in little endian order. This
-- wraps two calls nor_cmd_read() to get the full value.
--
local function nor_cmd_read16(nor, offset)
    local low = nor_cmd_read(nor, offset)
    local high = nor_cmd_read(nor, offset+1)
    return low + bit64.lshift(high, 8)
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
        nor:write(offset, data:sub(loc, loc + block_size))
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
    nor_cmd_write(nor, 0, 0xf0)
end

--
-- AMD based command set - Erase block
--
local function amd_erase(nor, offset)
    nor:reset(nor)
    -- Send the erase sector command sequence
    nor_cmd_write(nor, 0x555, 0xaa)
    nor_cmd_write(nor, 0x2aa, 0x55)
    nor_cmd_write(nor, 0x555, 0x80)
    nor_cmd_write(nor, 0x555, 0xaa)
    nor_cmd_write(nor, 0x2aa, 0x55)
    nor_write(nor.bootbus, offset, "\x30")

    -- Loop checking status
    local status = nor:readb(offset)
    local timeout = os.time() + 1
    while true do
        -- Read the status and xor it with the old status so we can
        -- find toggling bits
        local old_status = status
        status = nor:readb(offset)
        local toggle = bit64.bxor(status, old_status);
        -- Check if the erase in progress bit is toggling
        if bit64.btest(toggle, 0x40) then
            -- Check hardware timeout
            if bit64.btest(status, 0x20) then
                -- Chip has signalled a timeout. Reread the status
                old_status = nor:readb(offset)
                status = nor:readb(offset)
                toggle = bit64.bxor(status, old_status);
                -- Check if the erase in progress bit is toggling
                assert(not bit64.btest(toggle, 0x40), "NOR: Hardware timeout erasing block")
                -- Not toggling, erase complete
                break
            end
        else
            -- Not toggling, erase complete
            break
        end
        assert(os.time() <= timeout, "NOR: Timeout erasing block")
    end
    nor:reset(nor)
end

--
-- AMD based command set - Write block
--
local function amd_write(nor, offset, data)
    -- Loop through one byte at a time
    while #data > 0 do
        local to_write = data:sub(1,1)
        data = data:sub(2)
        -- Send the program sequence
        nor:reset(nor)
        nor_cmd_write(nor, 0x555, 0xaa)
        nor_cmd_write(nor, 0x2aa, 0x55)
        nor_cmd_write(nor, 0x555, 0xa0)
        nor_write(nor.bootbus, offset, to_write)

        -- Loop polling for status
        local timeout = os.time() + 1
        while true do
            local status = nor:readb(offset)
            if string.char(status) == to_write then
                -- Data matches, this byte is done
                break
            elseif bit64.btest(status, 0x20) then
                -- Hardware timeout, recheck status
                status = nor:readb(offset)
                assert(status == to_write, "NOR: Hardware write timeout")
            end
            assert(os.time() <= timeout, "NOR: Timeout writing block")
        end
        -- Increment to the next byte
        offset = offset + 1
    end
    nor:reset()
end

--
-- Intel based command set - Reset flash
-- Note: The NIC10E has an Intel based part
--
local function intel_reset(nor)
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
        status = nor:readb(offset)
    until bit64.btest(status, 0x80)
    return status
end

--
-- Intel based command set - Erase block
--
local function intel_erase(nor, offset)
    nor:reset(nor)
    -- Clear lock bits
    nor_write(nor.bootbus, offset, "\x60")
    nor_write(nor.bootbus, offset, "\xd0")
    intel_poll_status(nor, offset, "clear locks")
    -- Send the erase sector command sequence
    nor_write(nor.bootbus, offset, "\x20")
    nor_write(nor.bootbus, offset, "\xd0")
    intel_poll_status(nor, offset, "erase block")
    nor:reset(nor)
end

--
-- Intel based command set - Write block
--
local function intel_write(nor, offset, data)
    nor:reset(nor)
    -- Loop through one byte at a time
    for i=1, #data do
        local to_write = data:sub(i,i)
        local off = offset + i - 1
        -- Send the program sequence
        nor_write(nor.bootbus, off, "\x40")
        nor_write(nor.bootbus, off, to_write);
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
    -- Dummy read to make sure flash is in the normal access mode
    nor_read(nor.bootbus, 0, 1)
    -- Send reset command for both AMD and Intel command sets
    amd_reset(nor)
    intel_reset(nor)
    -- Send the query command
    nor_cmd_write(nor, 0x55, 0x98)
    -- Read CFI query identification string
    local result = nor_cmd_read(nor, 0x10)
    assert(result == 0x51, "Expected 'Q' from CFI query")
    local result = nor_cmd_read(nor, 0x11)
    assert(result == 0x52, "Expected 'R' from CFI query")
    local result = nor_cmd_read(nor, 0x12)
    assert(result == 0x59, "Expected 'Y' from CFI query")
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
       nor.write = amd_write
    else
        error("NOR: Unknown command set")
    end
    nor.burn = nor_burn
    function nor:read(offset, length)
        return nor_read(nor.bootbus, offset, length)
    end
    function nor:readb(offset)
        return nor_read(nor.bootbus, offset, 1):byte()
    end
    nor:reset()
    log:info("Flash info for chip select %d = \n", chip_sel)
    log:info(nor)
    return nor
end

--
-- This query function is the only module level function exposed. Call
-- it to get the NOR object instance.
--
function norflash.query(chip_sel)
    if not init_complete then
        init_bootbus()
        init_complete = true
    end
    return assert(cfi_query(chip_sel), "CFI Query failed")
end

return norflash
