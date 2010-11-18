--
-- Lua RPC implementation
-- Written by Chad Reese
-- Copyright (C) 2010-2011 Cavium Networks
-- This module is released under the standard Lua MIT license
--

require("strict")

--
-- Convert user supplied streams or file names into an input and output
-- file descriptor.
--
local function connectStreams(instream, outstream)
    local inf, outf
    if type(instream) == "string" then
        -- Open for RW in case we are running over Pipes. Linux pipes
        -- block until someone connects to the other side unless the
        -- pipe is openned RW.
        inf = io.open(instream, "r+b")
    elseif not instream then
        -- Embedded devices tend to mix RPC over the normal console
        inf = io.stdin
    else
        inf = instream
    end

    -- If no output stream was supplied assume we should use the same one
    -- as input. Useful for sockets and hardware devices.
    if not outstream then
        outstream = instream
    end

    if type(outstream) == "string" then
        -- Open for RW in case we are running over Pipes. Linux pipes
        -- block until someone connects to the other side unless the
        -- pipe is openned RW.
        outf = io.open(outstream, "r+b")
    elseif not outstream then
        -- Embedded devices tend to mix RPC over the normal console
        outf = io.stdout
    else
        outf = outstream
    end
    return inf, outf
end

--
-- Pack arguments into a remote param string
--
local function do_pack(...)
    local result = ""
    local args = {...}
    for i=1, #args do
        local arg = args[i]
        if arg == nil then
            result = result .. "n"
        elseif type(arg) == "boolean" then
            if arg then
	            result = result .. "t"
    	    else
    	        result = result .. "f"
    	    end
        elseif type(arg) == "number" then
            result = result .. "#" .. arg
        elseif type(arg) == "string" then
            result = result .. '"' .. arg .. '"'
        elseif type(arg) == "table" then
            result = result .. "{"
    	    for k,v in pairs(arg) do
    	        result = result .. do_pack(k) .. do_pack(v)
    	    end
    	    result = result .. "}"
        else
            error("Unsupported type '" .. type(arg) .. "'")
        end
    end
    return result
end

--
-- Unpack return data from a string
--
local function do_unpack(remote, start_index, str)
    local index = start_index   -- Current index in the string
    local length = #str         -- End of the string
    local result = {}           -- The container for unpacked results
    result.n = 0                -- Number of items in result

    -- print("Call do_unpack(" .. start_index .. ", \"" .. str .. "\")")

    -- Loop until we consume the string. We will exit early if we hit a table
    -- end marker. This is so we can recursively handle tables
    while index <= length do
        local v			                -- Value extracted from the string
        local c = str:sub(index,index)	-- Type char used to determine which type
	    index = index + 1
	    if c == "n" then	-- Nil
	        v = nil
	    elseif c == "t" then	-- Boolean true
	        v = true
	    elseif c == "f" then	-- Boolean false
	        v = false
	    elseif c == '"' then	-- String
            -- Find the ending quote, skipping escaped quotes
	        local start, fin = str:find('[^\\]"', index)
	        v = str:sub(index, fin - 1)
	        index = fin + 1
	    elseif c == "#" then	-- Number
            -- Numbers are a sequnce of decimal digits. The protocol guarantees
            -- that either a non digit follows a number or it is at the EOL
	        local start, fin = str:find("[0-9]+", index)
	        v = tonumber(str:sub(index, fin))
	        index = fin + 1
	    elseif c == "@" then	-- Remote object
            -- Remote object id is similar to a number
	        local start, fin = str:find("[0-9]+", index)
	        v = tonumber(str:sub(index, fin))
            v = remote.new(remote.inf, remote.outf, v)
	        index = fin + 1
	    elseif c == "{" then	-- Table begin
            -- Tables are stored as a sequence of key value pairs ended with a
            -- "}". Call do_unpack recursively to handle these.
            local t
            index, t = do_unpack(remote, index, str)
            -- Change the sequence into a table
            v = {}
            for i=1,#t,2 do
                v[t[i]] = t[i+1]
            end
	    elseif c == "}" then	-- Table end
            -- End of table. Break out and let the caller finish the string
            break
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
-- Do a remote command
--
local function do_remote(remote, command, ...)
    -- Build the remote command string
    local line = "$" .. command .. remote.remoteid .. do_pack(...)
    -- print(line)
    -- Send the string and flush to make sure it goes immediately
    remote.outf:write(line .. "\n")
    remote.outf:flush()
    -- Read lines unitl we get the response. Extra lines are displayed
    -- to stdout. We might be using the same serial channel for RPC and
    -- general output
    local d
    repeat
        -- Read a line
        line = remote.inf:read()
        if line:sub(-1) == '\r' then
            line = line:sub(1,-2)
        end
        -- Look for the start of response indicator
        d = line:find("$", 1, true)
        if d and (d > 1) then
            -- Write any extra stuff to the console
            io.write(line:sub(1, d-1))
        elseif not d then
            -- Write any extra stuff to the console
            io.write(line .. "\n")
        end
    until d
    -- Convert the response to Lua data structures
    local len, r = do_unpack(remote, d+1, line)
    -- Make sure we consumed all the input
    assert(len == #line + 1)
    -- Returned unpack data so calls work right
    return table.unpack(r, 1, r.n)
end

--
-- Create a new local object representing a remote object
--
local function rpc_new(instream, outstream, remoteid)
    local object = newproxy(true)
    local meta = getmetatable(object)
    meta.remoteid = remoteid
    meta.new = rpc_new
    meta.inf, meta.outf = connectStreams(instream, outstream)
    meta.__call = function(self, ...) return do_remote(getmetatable(self), "c", ...) end
    meta.__index = function(self, ...) return do_remote(getmetatable(self), "[", ...) end
    meta.__newindex = function(self, ...) do_remote(getmetatable(self), "=", ...) end
    meta.__len	= function(self) return do_remote(getmetatable(self), "#") end
    meta.__gc = function(self) do_remote(getmetatable(self), "~") end
    return object
end

--
-- Pack arguments into a remote param string
--
local function server_do_pack(objects, ...)
    local result = ""
    local args = {...}
    for i=1, #args do
        local arg = args[i]
        if arg == nil then
            result = result .. "n"
        elseif type(arg) == "boolean" then
            if arg then
	            result = result .. "t"
    	    else
    	        result = result .. "f"
    	    end
        elseif type(arg) == "number" then
            result = result .. "#" .. arg
        elseif type(arg) == "string" then
            result = result .. '"' .. arg .. '"'
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
            result = result .. "@" .. id
        end
    end
    return result
end

--
-- Table to contain our module
--
local rpc = {}

--
-- Create a new RPC connection to a remote rpc.serve
--
function rpc.connect(instream, outstream)
    return rpc_new(instream, outstream, 0)
end

--
-- Create a RPC server
--
function rpc.serve(instream, outstream)
    local inf, outf = connectStreams(instream, outstream)
    -- We keep a table of all objects that remote connections have a ref_id
    -- to. We can't let these objects garbage collect until all references are
    -- gone. The objects table is accessed either by reference number or
    -- the actual object. The reference number returns the object. The object
    -- returns a tuple containing the ref_id and the reference count.
    local objects = {}
    objects[0] = _G
    objects[_G] = {0, 1}
    while true do
        local dollar = inf:read(1)
        if dollar == "$" then
            -- Read the command
            local command = inf:read(1)
            local obj = inf:read("*n")
            local line = inf:read()

            -- Convert the command into an object reference and arguments
            local object = objects[obj]
            local _, args = do_unpack(nil, 1, line)
            local result = {}
            result.n = 0

            if command == "c" then      -- Function call
                result = table.pack(object(table.unpack(args, 1, args.n)))
            elseif command == "[" then  -- Index to get table value
                result[1] = object[args[1]]
                result.n = 1
            elseif command == "=" then  -- Assignment of a table value
                rawset(object, args[1], args[2])
            elseif command == "#" then  -- Get the length of an object
                result[1] = #object
                result.n = 1
            elseif command == "~" then  -- Delete reference to object
                local obj_info = objects[object]
                obj_info[2] = obj_info[2] - 1
                if obj_info[2] == 0 then
                    -- All references are gone, allow garbage collection
                    objects[object] = nil
                    objects[obj] = nil
                end
            else
                error ("Illegal remote command " .. command)
            end
            -- Write the response and flush it
            outf:write("$" .. server_do_pack(objects, table.unpack(result, 1, result.n)) .. "\n")
            outf:flush()
        else
            -- Not a command, just echo out extra junk
            io.write(dollar)
        end
    end
end

--
-- Needed for compatibility with Lua 5.1
--
if rawget(table, "unpack") == nil then
    table.unpack = unpack
end

return rpc
