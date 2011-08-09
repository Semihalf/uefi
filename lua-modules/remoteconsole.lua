require("strict")
require("utils")
local oremote = require("oremote")

local remoteconsole = {}
local REMOTE_ADDRESS = 0x500
local REMOTE_MAGIC = "CONS"
local REMOTE_VERSION = "\x01"
local pending_data = ""

local function poll_read()
    repeat
        local l = oremote.read_mem(REMOTE_ADDRESS+7, 1):byte()
        if l > 0 then
            local data = oremote.read_mem(REMOTE_ADDRESS+260, l)
            pending_data = pending_data .. data
            oremote.write_mem(REMOTE_ADDRESS+7, "\x00")
        end
    until l == 0
end

local function rem_read(handle, format)
    poll_read()
    local l = pending_data
    pending_data = ""
    return l
end

local function rem_write(handle, data)
    while #data > 0 do
        repeat
            poll_read()
            local l = oremote.read_mem(REMOTE_ADDRESS+6, 1):byte()
        until l == 0
        local l = #data
        if l > 252 then
            l = 252
        end
        local d = data:sub(1,l)
        oremote.write_mem(REMOTE_ADDRESS+8, d)
        oremote.write_mem(REMOTE_ADDRESS+6, string.char(l))
        data = data:sub(l + 1)
    end
end

function remoteconsole.open()
    local magic = oremote.read_mem(REMOTE_ADDRESS, 4)
    assert(REMOTE_MAGIC == magic, "Invalid remote console magic number")
    local version = oremote.read_mem(REMOTE_ADDRESS+4, 1)
    assert(REMOTE_VERSION == version, "Invalid remote console version number")
    local handle = {}
    handle.read = rem_read
    handle.write = rem_write
    return handle
end

function remoteconsole.run()
    printf("Hit Control-A to exit console\n")
    local handle = remoteconsole.open()
    while true do
        local input = handle:read()
        if #input then
            io.write(input)
            io.flush()
        end
        local output = oremote.getkey()
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
