#!/usr/bin/env bdk-lua

--
-- Lua script for automating scripts that use menu and readline
--
require("strict")
require("utils")
require("menu")
local rpc_support = require("rpc-support")
local readline = require("readline")
local debug = require("debug")
local s_pack = rpc_support.string_pack
local s_unpack = rpc_support.string_unpack

--
-- State variables for recording and playing back
--
local doing_recording
local recording_file
local script_line_no = 0
local script_line
local output_buffer = {}

--
-- We're going to replace readline and the print functions so we can
-- intercept all input and output done a by a secondary script. These
-- local variables keep a copy of the original values so we can do
-- output.
--
local real_readline = readline.readline
local print = print
local printf = printf

--
-- Enable the diplay of menu keys by default. You should use the
-- keys instead of the menu options when making recordings in case
-- menu order changes in the future.
--
menu.show_keys = true

--
-- Use a local version off assert() instead of Lua's default. The normal
-- assert function uses print, which interferes with our processing of
-- script output. This function is used for asserts in this file, but
-- not the script that is actually running.
--
local function assert(value, message)
    if value then
        return value
    end
    -- Print messages with red background
    printf("\27[41m\nASSERT ERROR[bdk-record]\n%s", message)
    if script_line then
        printf("\nScript line:\n[%4d]%s", script_line_no, script_line)
    end
    printf("\27[0m\n\n")
    os.exit(false, true)
end

--
-- Record an operation that can be played back later. The arguments
-- are a string type followed by optional arguments. The arguments
-- are separated by spaces and escaped as strings.
--
local function record(...)
    local t = table.pack(...)
    for i=2,t.n do
        t[i] = s_pack(t[i])
    end
    recording_file:write(table.concat(t, " "))
    recording_file:write("\n")
end

--
-- Get a line from the script file, skipping comments and updating
-- line numbers.
--
local function get_script_line()
    if not script_line then
        repeat
            script_line = assert(recording_file:read("*l"))
            script_line_no = script_line_no + 1
        until script_line:sub(1,1) ~= "#"
    end
    return script_line
end

--
-- Retire a script line after its use is complete
--
local function retire_script_line()
    script_line = nil
end

--
-- Checks that a line of output matches the rule for it in the
-- script recording.
--
local function check(output)
    local script_line = get_script_line()
    local action = script_line:match("%w+")
    if action == "match" then
        -- Check for an exact string match
        local loc, s = s_unpack(#action+3, script_line)
        assert(loc == #script_line + 1, "Format error in script match line")
        assert(s == output, "Output doesn't match:\n\t" .. s_pack(output))
        retire_script_line()
    elseif action == "skipto" then
        -- Search for an exact string match
        local loc, s = s_unpack(#action+3, script_line)
        assert(loc == #script_line + 1, "Format error in script skipto line")
        if s == output then
            retire_script_line()
        end
    elseif action == "pattern" then
        -- Check for a pattern string match
        local loc, s = s_unpack(#action+3, script_line)
        assert(loc == #script_line + 1, "Format error in script match line")
        assert(output:match("^" .. s .. "$"), "Output doesn't match:\n\t" .. s_pack(output))
        retire_script_line()
    else
        assert(false, "Unexpected action in script")
    end
end

--
-- We want to match entire lines whenever possible, so the scripts
-- write will buffer input until we get full lines. It will then
-- record the full line.
--
local function script_write(output)
    -- Put output into a table until we get a newline
    table.insert(output_buffer, output)
    if output:find("\n") then
        -- Covert the output into one big string
        local all = table.concat(output_buffer)
        -- Break the output into lines
        local i = all:find("\n")
        while i do
            local l = all:sub(1, i)
            if doing_recording then
                -- Save line as an exact match
                record("match", l)
                io.write(l)
            else
                -- Check the line
                check(l)
                printf("[%4d]%s", script_line_no, l)
            end
            -- Move to the next output line
            all = all:sub(i+1)
            i = all:find("\n")
        end
        -- Output table is now empty
        output_buffer = {}
    end
end

--
-- Sometimes it is necessary to flush the buffer write. This
-- is useful before we ask for input.
--
local function script_flush()
    if next(output_buffer) then
        -- Covert the output into one big string
        local all = table.concat(output_buffer)
        if doing_recording then
            -- Save partial line as an exact match
            record("match", all)
            io.write(all)
        else
            -- Check the partial line
            check(all)
            printf("[%4d]%s", script_line_no, all)
        end
        -- Output table is now empty
        output_buffer = {}
    end
end

--
-- Wrapper around readline that allows us to record the operation
--
local function script_readline(prompt, tab_complete, timeout_us)
    -- Flush any pending output
    script_flush()
    if doing_recording then
        local input = real_readline(prompt, tab_complete, timeout_us)
        if input then
            record("prompt", prompt, input)
        end
        return input
    else
        local script_line = get_script_line()
        assert(script_line:sub(1,6) == "prompt", "Expected prompt line")
        local loc, p = s_unpack(9, script_line)
        local loc, input = s_unpack(loc+2, script_line)
        assert(loc == #script_line + 1, "Format error in prompt line")
        assert(p == prompt, "Incorrect prompt request: " .. s_pack(prompt))
        printf("\27[33m[%4d]%s%s\27[0m\n", script_line_no, prompt, input)
        retire_script_line()
        return input
    end
end
readline.readline = script_readline

--
-- Replacement for the general print that records its output
--
local function script_print(...)
    local t = table.pack(...)
    local l = nil
    for i=1,t.n do
        if l then
            l = l .. "\t" .. tostring(t[i])
        else
            l = tostring(t[i])
        end
    end
    if l then
        script_write(l .. "\n")
    else
        script_write("\n")
    end
end
_G["print"] = script_print

--
-- Replacement for the general printf that records its output
--
local function script_printf(...)
    script_write(string.format(...))
end
_G["printf"] = script_printf

--
-- Execute the user's script, fixing arguments as needed
--
local function run_script()
    -- Shift arguments so scripts gets its name as arg[0]
    for i=3,#arg do
        arg[i-3] = arg[i]
    end
    -- Delete the three extra duplicates
    table.remove(arg)
    table.remove(arg)
    table.remove(arg)
    -- Run the script
    dofile(arg[0])
end

--
-- Handle our arguments
--
if #arg < 3 then
    local help =
[[

    bdk-record help
        Display this help message.

    bdk-record record record_file script [arguments ...]
        Record interaction with <script> into <record_file>.

    bdk-record play record_file script [arguments ...]
        Play <record_file> while running <script> and compare the results.
]]
    print(help)
    os.exit(false, true)

elseif arg[1] == "record" then
    doing_recording = true
    recording_file = assert(io.open(arg[2], "w"))
    recording_file:write(
[[
#
# Recording file created by bdk-record.lua.
# Each line represents an action needed for the script being run.
# match:    The string argument must be exactly match the scripts output.
# skipto:   The string argument must be exactly a line in the scripts output.
# pattern:  The string argument must be patten match a line in the scripts output.
# prompt:   The prompt argument must exactly match the argument to readline, The second argument is given as input.
# Lines beginning with "#" are ignored.
#
]])
    run_script()
    recording_file:close()
    return 0;

elseif arg[1] == "play" then
    doing_recording = false
    recording_file = assert(io.open(arg[2], "r"))
    run_script()
    recording_file:close()
    return 0;

else
    print("ERROR: First argument must either be \"help\", \"record\" or \"play\".")
    os.exit(false, true)
end

