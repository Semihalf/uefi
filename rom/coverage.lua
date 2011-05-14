--
-- Lua coverage implementation
-- Written by Chad Reese
-- Copyright (C) 2010-2011 Cavium Networks
-- This module is released under the standard Lua MIT license
--

local debug = require("debug")

coverage = {}
coverage.data = {}

--
-- Called every time Lua executes a line
--
local function coverage_hook(reason, lineno)
    local info = debug.getinfo(2, "Sl")
    local filename = tostring(info.short_src)
    local lineno = info.currentline
    if not coverage.data[filename] then
        coverage.data[filename] = {}
    end
    if not coverage.data[filename][lineno] then
        coverage.data[filename][lineno] = 0
    end
    coverage.data[filename][lineno] = coverage.data[filename][lineno] + 1
end

--
-- Start coverage analysis
--
function coverage.start()
    debug.sethook(coverage_hook, "l")
end

--
-- Stop coverage analysis
--
function coverage.stop()
    debug.sethook()
end

--
-- Report coverage analysis
--
function coverage.report()
    local skip_expressions = {
        "^ *[-][-]", -- Comment lines
        "^ *\n$", -- Empty lines
        "^ *}\n$", -- Lines ending table defines
        "^ *end\n$", -- end by itself
        "^ *else\n$", -- else by itself
        "^local function", -- Local function prototypes
    }
    print("Coverage Report")
    coverage.stop()
    for filename, filedata in pairs(coverage.data) do
        local infile = io.open(filename, "r")
        if infile then
            local outfile = assert(io.open(filename .. ".coverage", "w"))
            local count = 0
            local miss = 0
            local line = infile:read("*L")
            while line do
                count = count + 1
                local prefix = nil
                if filedata[count] then
                    prefix = string.format("%7d:", count)
                else
                    for _,pattern in ipairs(skip_expressions) do
                        if line:match(pattern) then
                            prefix = "       :"
                            break
                        end
                    end
                    if not prefix then
                        prefix = "#######:"
                        miss = miss + 1
                    end
                end
                outfile:write(prefix)
                outfile:write(line)
                line = infile:read("*L")
            end
            outfile:close()
            infile:close()
            if count > 0 then
                print(filename, tostring(100*(count - miss) / count) .. "%")
            end
        end
    end
end

-- Create a report when Lua exits
coverage.on_gc = newproxy(true)
local meta = getmetatable(coverage.on_gc)
meta.__gc = coverage.report

-- Start coverage by default
coverage.start()

return coverage
