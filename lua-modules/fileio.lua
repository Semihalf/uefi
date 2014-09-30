---
-- Lua module supporting higher level file operations
-- that are common using the BDK's virtual filesystem.
--
-- * Written by Chad Reese
-- * Copyright (C) 2010-2014 Cavium Inc.
--
require("strict")
require("utils")

fileio = {}
--- Maximum size of block to transfer in one read/write
fileio.block_size = 512

--- Open a file, throwing an exception on failure
-- @param filename File to open.
-- @param mode File open mode to pass into io.open().
-- @param seek_to Location to seek to in the file, or nil
-- @return File handle
function fileio.open(filename, mode, seek_to)
    assert(type(filename) == "string")
    assert(type(mode) == "string")
    assert((seek_to == nil) or tonumber(seek_to))
    local handle
    if isglobal("cavium") and (filename:sub(1,5) == "/dev/") then
        handle = assert(cavium.devopen(filename, mode))
    else
        handle = assert(io.open(filename, mode))
    end
    if seek_to then
        local loc = handle:seek("set", seek_to)
        if not loc then
            error('Seek failed in file "' .. filename ..'"')
        end
    end
    return handle
end

--- Transfer data from one file handle to another.
function fileio.transfer(source_handle, dest_handle, length)
    local on_target, unused = pcall(require, "cavium-internal")
    if length == nil then
        -- Assume no file is larger than 64GB
        length = 0x1000000000
    end
    local transfer_count = 0
    while transfer_count < length do
        local l = length - transfer_count
        if l > fileio.block_size then
            l = fileio.block_size
        end
        local data = source_handle:read(l)
        if data == nil then
            break
        end
        dest_handle:write(data)
        transfer_count = transfer_count + #data
        if not on_target then
            printf("\rTransferred %7d bytes", transfer_count)
        end
    end
    if not on_target then
        printf("\n")
    end
    return transfer_count
end

--- Copy data from one file to another.
function fileio.copy(source, source_seek, dest, dest_seek, length)
    local close_source = false
    local close_dest = false
    if type(source) == "string" then
        source = fileio.open(source, "r", source_seek)
        close_source = true
    end
    if type(dest) == "string" then
        dest = fileio.open(dest, "w", dest_seek)
        close_dest = true
    end
    local count = fileio.transfer(source, dest, length)
    if close_source then
        source:close()
    end
    if close_dest then
        dest:close()
    end
    return count
end


--- Hex dump a file.
function fileio.hexdump(source, seek_to, length)
    local close_source = false
    if type(source) == "string" then
        source = fileio.open(source, "r", seek_to)
        close_source = true
    end

    local loc = source:seek("cur")
    local last_data
    local repeat_count = 0
    local data
    if (not length) or (length >= 16) then
        data = source:read(16)
    else
        data = source:read(length)
    end
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
        if length then
            length = length - #data
            if length >= 16 then
                data = source:read(16)
            elseif length == 0 then
                data = nil
            else
                data = source:read(length)
            end
        else
            data = source:read(16)
        end
        loc = loc + 16
    end
    if close_source then
        source:close()
    end
end

return fileio
