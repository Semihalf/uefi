---
-- Module to support accessing the console over OCTEON_REMOTE_PROTOCOL.
--
-- * Written by Chad Reese
-- * Copyright (C) 2010-2013 Cavium Networks
--
require("strict")
require("utils")
local oremote = require("oremote")
local logging = require("logging")
local log = logging.new("RemoteConsole")
local readline = require("readline")

local remoteconsole = {}
local REMOTE_ADDRESS = 0x500
local REMOTE_MAGIC = "CONS"
local REMOTE_VERSION = "\x01"
local pending_data = ""

local function poll_read()
    local pending_write
    repeat
        local l = oremote.read_mem(REMOTE_ADDRESS+6, 2)
        pending_write = l:sub(1,1):byte()
        l = l:sub(2,2):byte()
        if l > 0 then
            local data = oremote.read_mem(REMOTE_ADDRESS+260, l)
            if log.level == logging.DEBUG then
                log:debug("Read %s\n", data:hex())
            end
            pending_data = pending_data .. data
            oremote.write_mem(REMOTE_ADDRESS+7, "\x00")
        end
    until l == 0
    return pending_write
end

local function rem_read(handle, format)
    while true do
        poll_read()
        if (format == nil) or (format == "*l") then
            local l = pending_data:find("\n")
            if l then
                local result = pending_data:sub(1,l-1)
                pending_data = pending_data:sub(l+1)
                return result
            end
        elseif format == "*L" then
            local l = pending_data:find("\n")
            if l then
                local result = pending_data:sub(1,l)
                pending_data = pending_data:sub(l+1)
                return result
            end
        elseif format == "*a" then
            local result = pending_data
            pending_data = ""
            return result
        else
            error("Unsupported format type " .. tostring(format))
        end
    end
end

local function rem_write(handle, data)
    while #data > 0 do
        repeat
            local l = poll_read()
        until l == 0
        local l = #data
        if l > 252 then
            l = 252
        end
        local d = data:sub(1,l)
        if log.level == logging.DEBUG then
            log:debug("Write %s\n", d:hex())
        end
        oremote.write_mem(REMOTE_ADDRESS+8, d)
        oremote.write_mem(REMOTE_ADDRESS+6, string.char(l))
        data = data:sub(l + 1)
    end
end

--- Open a remote console
-- @return Object similar to a file handle
function remoteconsole.open()
    local magic = oremote.read_mem(REMOTE_ADDRESS, 4)
    log:info("Magic = %s\n", magic)
    assert(REMOTE_MAGIC == magic, "Invalid remote console magic number")
    local version = oremote.read_mem(REMOTE_ADDRESS+4, 1)
    log:info("Version = %s\n", version:hex())
    assert(REMOTE_VERSION == version, "Invalid remote console version number")
    local handle = {}
    handle.read = rem_read
    handle.write = rem_write
    handle.flush = function() end
    return handle
end

--- Create an interactive terminal for accessing the remote console
function remoteconsole.run()
    printf("Hit Control-A to exit console\n")
    local handle = remoteconsole.open()
    while true do
        local input = handle:read("*a")
        if #input then
            io.write(input)
            io.flush()
        end
        local output = readline.getkey(1000)
        if output then
            if output == "\x01" then
                printf("\nConsole exited due to Control-A\n")
                break
            end
            handle:write(output)
        end
    end
end

return remoteconsole
