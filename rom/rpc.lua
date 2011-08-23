--
-- Lua RPC implementation
-- Written by Chad Reese
-- Copyright (C) 2010-2011 Cavium Networks
-- This module is released under the standard Lua MIT license
--

require("strict")
require("utils")
local bit64 = require("bit64")
local debug = require("debug")

local RPC_BEGIN = "$"
local RPC_END = "\n"
local is_server = false

--
-- Table to contain our module
--
rpc = {}
rpc.debug = false

local function getconnection(stream, is_input)
    if type(stream) == "string" then
        -- Set the baud rate for filenames that start with "/". This
        -- is a best guess of what should work for people
        if stream:sub(1,1) == "/" then
            os.execute("stty -F " .. stream .. " 115200 -crtscts -cstopb -parenb")
        end
        -- Open for RW in case we are running over Pipes. Linux pipes
        -- block until someone connects to the other side unless the
        -- pipe is openned RW.
        local f = io.open(stream, "r+b")
        if f then
            return f
        end
        assert(not stream:find("/"), "Failed to open file " .. stream)
        -- Not a file, try a TCP connection
        -- Default to the telnet port if not specified
        local host = stream
        local port = 23
        if stream:find(":") then
            local sep = stream:find(":")
            host = stream:sub(1,sep-1)
            port = tonumber(stream:sub(sep+1))
        end
        -- Create a wrapper that makes a socket work like a file
        f = {}
        function f:read(arg)
            local r, message = self.s:receive(arg)
            assert(r, "socket:receive(): " .. tostring(message))
            return r
        end
        function f:write(arg)
            local status, message = self.s:send(arg)
            assert(status == #arg, "socket:send(): " .. tostring(message))
        end
        function f:flush(arg)
            -- Do nothing
        end
        -- Create a scoket connection
        local socket = require("socket")
        f.s = socket.tcp()
        f.s:setoption("tcp-nodelay", true)
        local status, message = f.s:connect(host, port)
        assert(status, "socket:connect(): " .. tostring(message))
        return f
    elseif not stream then
        -- Use standard IO if nothing specified
        if is_input then
            return io.stdin
        else
            return io.stdout
        end
    else
        -- Assume the passed object supports read and write
        return stream
    end
end

--
-- Convert user supplied streams or file names into an input and output
-- file descriptor.
--
local function connectStreams(instream, outstream)
    local inf, outf
    if instream == "remote" then
        local oremote = require("oremote")
        local remoteconsole = require("remoteconsole")
        local handle = remoteconsole.open()
        return handle, handle
    end
    inf = getconnection(instream, true)
    if outstream then
        outf = getconnection(outstream, false)
    else
        -- If no output stream was supplied assume we should use the same one
        -- as input. Useful for sockets and hardware devices.
        outf = inf
    end
    return inf, outf
end

local function string_pack(s)
    local r = {'"'}
    for i=1,#s do
        local b = s:byte(i,i)
        -- Escape control chars (<32), high characters (>126), double
        -- quote (34), and backslash (92)
        if (b < 32) or (b > 126) or (b == 34) or (b == 92) then
            table.insert(r, "\\%02x" % b)
        else
            table.insert(r, s:sub(i,i))
        end
    end
    table.insert(r, '"')
    return table.concat(r)
end

local function string_unpack(index, str)
    local fin = #str
    local i = index
    local r = {}
    while i <= fin do
        local c = str:sub(i,i)
        if c == "\\" then
            local hex = assert(tonumber(str:sub(i+1,i+2), 16), "Expected two hex digits")
            table.insert(r, string.char(hex))
            i = i + 2
        elseif c == '"' then
            return i+1, table.concat(r)
        else
            table.insert(r, c)
        end
        i = i + 1
    end
    error("Ran out of data processing string")
end

--
-- Pack arguments into a remote param string
--
local function do_pack(...)
    local result = {}
    local args = {...}
    for i=1, #args do
        local arg = args[i]
        local argtype = type(arg)
        if arg == nil then
            table.insert(result, "n")
        elseif argtype == "boolean" then
            if arg then
                table.insert(result, "t")
            else
                table.insert(result, "f")
            end
        elseif argtype == "number" then
            table.insert(result, "#")
            table.insert(result, arg)
        elseif argtype == "string" then
            table.insert(result, string_pack(arg))
        elseif argtype == "table" then
            table.insert(result, "{")
            for k,v in pairs(arg) do
                table.insert(result, do_pack(k))
                table.insert(result, do_pack(v))
            end
            table.insert(result, "}")
        elseif argtype == "userdata" then
            local meta = getmetatable(arg)
            table.insert(result, "@")
            table.insert(result, meta.getid(arg))
        else
            error("Unsupported type '" .. argtype .. "'")
        end
    end
    return table.concat(result)
end

--
-- Unpack return data from a string
--
local function do_unpack(remote, start_index, str, is_server)
    local index = start_index   -- Current index in the string
    local length = #str         -- End of the string
    local result = {}           -- The container for unpacked results
    result.n = 0                -- Number of items in result

    -- print("Call do_unpack(" .. start_index .. ", \"" .. str .. "\")")

    -- Loop until we consume the string. We will exit early if we hit a table
    -- end marker. This is so we can recursively handle tables
    while index <= length do
        local v                         -- Value extracted from the string
        local c = str:sub(index,index)  -- Type char used to determine which type
        index = index + 1
        if c == "n" then    -- Nil
            v = nil
        elseif c == "t" then    -- Boolean true
            v = true
        elseif c == "f" then    -- Boolean false
            v = false
        elseif c == '"' then    -- String
            index, v = string_unpack(index, str)
        elseif c == "#" then    -- Number
            -- Numbers are a sequnce of decimal digits. The protocol guarantees
            -- that either a non digit follows a number or it is at the EOL
            local start, fin = str:find("[0-9]+", index)
            v = tonumber(str:sub(index, fin))
            index = fin + 1
        elseif c == "@" then    -- Remote object
            -- Remote object id is similar to a number
            local start, fin = str:find("[0-9]+", index)
            v = tonumber(str:sub(index, fin))
            if is_server then
                v = rpc.objects[v]
            else
                v = getmetatable(remote).new(remote, v)
            end
            index = fin + 1
        elseif c == "{" then    -- Table begin
            -- Tables are stored as a sequence of key value pairs ended with a
            -- "}". Call do_unpack recursively to handle these.
            local t
            index, t = do_unpack(remote, index, str, is_server)
            -- Change the sequence into a table
            v = {}
            for i=1,#t,2 do
                v[t[i]] = t[i+1]
            end
        elseif c == "}" then    -- Table end
            -- End of table. Break out and let the caller finish the string
            break
        elseif c == "e" then    -- Error exception
            local t
            index, t = do_unpack(remote, index, str, is_server)
            error(t[1])
        else
            error('Unexpected format char at ' .. (index-1) .. ' in  "' .. str .. '"')
        end
        -- Add the latest value to the end of the results
        result.n = result.n + 1
        result[result.n] = v
    end
    -- print("return do_unpack(" .. index .. ")")
    return index, result
end

--
-- Calculate the correct checksum for a line and return it in a string read
-- for transmit
--
local function get_checksum(line)
    local checksum = 0
    for i=1,#line do
        checksum = checksum + line:sub(i,i):byte()
    end
    checksum = bit64.band(checksum, 0xff)
    return "#%02x" % checksum
end

--
-- Send a RPC command
--
local function send_command(inf, outf, line)
    -- Add the checksum
    line = line .. get_checksum(line)
    -- Debug output as necessary
    if rpc.debug then
        if is_server then
            io.write("[RPC Server Response]" .. line .. "\n")
        else
            io.write("[RPC Send]" .. line .. "\n")
        end
    end
    -- Send the string and flush to make sure it goes immediately
    outf:write(RPC_BEGIN .. line .. RPC_END)
    outf:flush()
end

--
-- Receive a RPC command
--
local function receive_command(inf, outf)
    -- Read lines unitl we get the response. Extra lines are displayed
    -- to stdout. We might be using the same serial channel for RPC and
    -- general output
    local result
    repeat
        -- Read a line
        result = inf:read()
        -- Strip off ending carriage returns
        if result:sub(-1) == '\r' then
            result = result:sub(1,-2)
        end
        -- Look for the start of response indicator
        local d = result:find(RPC_BEGIN, 1, true)
        if d and (d > 1) then
            -- Write any extra stuff to the console
            io.write(result:sub(1, d-1))
            result = result:sub(d)
        elseif not d then
            -- Write any extra stuff to the console
            io.write(result)
            io.write("\n")
        end
    until d

    -- Strip the RPC_BEGIN header
    result = result:sub(2)

    -- Log debug output of what we recieved
    if rpc.debug then
        if is_server then
            io.write("[RPC Server Request]" .. result .. "\n")
        else
            io.write("[RPC Receive]" .. result .. "\n")
        end
    end

    -- Check that the length could contain a checksum
    if #result < 3 then
        io.write("[RPC ERROR]Too short to have checksum\n")
        return nil
    end

    -- Verify the checksum
    local got_checksum = result:sub(-3)
    local result = result:sub(1,-4)
    local checksum = get_checksum(result)
    if checksum ~= got_checksum then
        io.write("[RPC ERROR]Incorrect checksum\n")
        return nil
    end

    -- Everything is good
    return result
end

--
-- Do a remote command
--
local function do_remote_command(remote, line)
    local meta = getmetatable(remote)
    local command
    repeat
        send_command(meta.inf, meta.outf, line)
        command = receive_command(meta.inf, meta.outf)
    until command
    -- Convert the response to Lua data structures
    local len, r = do_unpack(remote, 1, command, false)
    -- Make sure we consumed all the input
    assert(len == #command+1)
    -- Returned unpack data so calls work right
    return table.unpack(r, 1, r.n)
end

--
-- Do a remote on a specific object
--
local function rpc_object_remote(self, command, ...)
    local meta = getmetatable(self)
    -- Cleanup any remote objects that have been garbage collected
    if #meta.need_cleanup > 0 then
        do_remote_command(self, "~" .. table.concat(meta.need_cleanup, "#"))
        meta.need_cleanup = {}
    end
    -- Build the comamnd
    local line = command .. meta.getid(self) .. do_pack(...)
    -- Do the command and return the results
    return do_remote_command(self, line)
end

local function rpc_object_getid(self)
    local meta = getmetatable(self)
    return meta.remoteid[self]
end

local function rpc_object_call(self, ...)
    return rpc_object_remote(self, "c", ...)
end

local function rpc_object_index(self, key)
    return rpc_object_remote(self, "[", key)
end

local function rpc_object_setindex(self, key, value)
    rpc_object_remote(self, "=", key, value)
end

local function rpc_object_len(self)
    return rpc_object_remote(self, "#")
end

local function rpc_object_gc(self)
    local meta = getmetatable(self)
    local remoteid = meta.remoteid[self]
    table.insert(meta.need_cleanup, remoteid)
    meta.remoteid[self] = nil
end

--
-- Create a new local object representing a remote object
--
local function rpc_object_new(self, remoteid)
    local mymeta = getmetatable(self)
    local object = newproxy(self)
    mymeta.remoteid[object] = tostring(remoteid)
    return object
end

local function rpc_object_pairs(self)
    local g = rpc_object_new(self, 0)
    local p = rpc_object_remote(g, "[", "pairs")
    return rpc_object_remote(p, "c", self)
end

local function rpc_object_ipairs(self)
    local g = rpc_object_new(self, 0)
    local p = rpc_object_remote(g, "[", "ipairs")
    return rpc_object_remote(p, "c", self)
end

--
-- Create a new RPC connection to a remote rpc.serve
--
function rpc.connect(instream, outstream)
    local object = newproxy(true)
    local meta = getmetatable(object)
    -- Table used to track remote numeric IDs
    local m = {}
    m.__mode = "k"
    meta.remoteid = {}
    setmetatable(meta.remoteid, m)
    meta.remoteid[object] = "0"
    -- Table used to track objects to delete
    meta.need_cleanup = {}
    -- Methods for the remote object
    meta.new = rpc_object_new
    meta.getid = rpc_object_getid
    meta.__call = rpc_object_call
    meta.__index = rpc_object_index
    meta.__newindex = rpc_object_setindex
    meta.__len  = rpc_object_len
    meta.__gc = rpc_object_gc
    meta.__pairs = rpc_object_pairs
    meta.__ipairs = rpc_object_ipairs
    -- File handles for communications
    meta.inf, meta.outf = connectStreams(instream, outstream)
    return object
end

--
-- Pack arguments into a remote param string
--
local function server_do_pack(objects, ...)
    local result = {}
    local args = {...}
    for i=1, #args do
        local arg = args[i]
        local argtype = type(arg)
        if arg == nil then
            table.insert(result, "n")
        elseif argtype == "boolean" then
            if arg then
                table.insert(result, "t")
            else
                table.insert(result, "f")
            end
        elseif argtype == "number" then
            table.insert(result, "#")
            table.insert(result, arg)
        elseif argtype == "string" then
            table.insert(result, string_pack(arg))
        elseif (argtype == "table") and not getmetatable(arg) then
            table.insert(result, "{")
            for k,v in pairs(arg) do
                table.insert(result, server_do_pack(objects, k, v))
            end
            table.insert(result, "}")
        else
            -- Try and treat any other types as generic remote objects
            -- All accesses to them will cause RPC calls
            local id
            if objects[arg] then
                local obj_info = objects[arg]
                id = obj_info[1]
                obj_info[2] = obj_info[2] + 1
            else
                id = #objects + 1
                objects[id] = arg
                objects[arg] = {id, 1}
            end
            table.insert(result, '@')
            table.insert(result, id)
        end
    end
    return table.concat(result)
end

--
-- Create a RPC server
--
local function rpc_serve(inf, outf, only_one)
    -- We keep a table of all objects that remote connections have a ref_id
    -- to. We can't let these objects garbage collect until all references are
    -- gone. The objects table is accessed either by reference number or
    -- the actual object. The reference number returns the object. The object
    -- returns a tuple containing the ref_id and the reference count.
    if not rpc.objects then
        rpc.objects = {}
        rpc.objects[0] = _ENV
        rpc.objects[_ENV] = {0, 1}
    end
    repeat
        local full_command = receive_command(inf, outf)
        if full_command then
            local command = full_command:sub(1,1)
            local obj = full_command:match("^%d+", 2)
            local line = full_command:sub(#obj + 2)
            obj = tonumber(obj)

            -- Convert the command into an object reference and arguments
            local object = rpc.objects[obj]
            local _, args = do_unpack(nil, 1, line, true)
            local result = {}
            result.n = 0

            if command == "c" then      -- Function call
                result = table.pack(object(table.unpack(args, 1, args.n)))
            elseif command == "[" then  -- Index to get table value
                result[1] = object[args[1]]
                result.n = 1
            elseif command == "=" then  -- Assignment of a table value
                if object == _G then
                    -- Strict might be loaded and not allow setting globals
                    -- Bypass it by using rawset
                    rawset(object, args[1], args[2])
                else
                    object[args[1]] = args[2]
                end
            elseif command == "#" then  -- Get the length of an object
                result[1] = #object
                result.n = 1
            elseif command == "~" then  -- Delete reference to object
                table.insert(args, obj)
                for _,obj in ipairs(args) do
                    local object = rpc.objects[obj]
                    local obj_info = rpc.objects[object]
                    obj_info[2] = obj_info[2] - 1
                    if (obj ~= 0) and (obj_info[2] == 0) then
                        -- All references are gone, allow garbage collection
                        rpc.objects[object] = nil
                        rpc.objects[obj] = nil
                    end
                end
            else
                error ("Illegal remote command " .. command)
            end
            line = server_do_pack(rpc.objects, table.unpack(result, 1, result.n))
            -- Write the response and flush it
            send_command(inf, outf, line)
            -- Force a GC if we released objects. We do this here so the
            -- response isn't delayed by GC
            if command == "~" then
                collectgarbage()
            end
        end
    until only_one
end

--
-- Create a RPC server
--
function rpc.serve(only_one)
    is_server = true
    local status, message = xpcall(rpc_serve, debug.traceback, io.stdin, io.stdout, only_one)
    if not status then
        send_command(io.stdin, io.stdout, "e" .. server_do_pack(rpc.objects, message))
    end
    is_server = false
end

--
-- Needed for compatibility with Lua 5.1
--
if rawget(table, "unpack") == nil then
    table.unpack = unpack
end

return rpc
