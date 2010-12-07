
require("strict")
require("utils")

local GOTO_TOP      = "\27[1;1H"   -- ESC[1;1H begins output at the top of the terminal (line 1)
local GOTO_BOTTOM   = "\27[100;1H" -- ESC[1;1H begins output at the bottom of the terminal (actually line 100)
local GOTO_BOL      = "\27[100D"   -- Go to beginning of line
local ERASE_EOL     = "\27[0K"     -- Erase to end of line
local ERASE_EOS     = "\27[0J"     -- Erase to end screen
local ERASE_WIN     = "\27[2J"     -- Erase the window
local REVERSE       = "\27[7m"     -- Reverse the display
local NORMAL        = "\27[0m"     -- Normal display
local NONZEROHI     = "\27[33m"    -- Yellow used for non zero rows
local ZEROHI        = "\27[32m"    -- Green used for zero rows
local SCROLL_FULL   = "\27[1;r"    -- Normal full-screen scrolling for statistics region
local CURSOR_ON     = "\27[?25h"   -- Turn on cursor
local CURSOR_OFF    = "\27[?25l"   -- Turn off cursor

local Row = {}
local row_counter = 0
function Row.new(name, struct, field, has_totals)
    local self = {}
    row_counter = row_counter + 1
    -- Private variables

    -- Public variables
    self.name = name
    self.visible = (struct == "stats")
    self.number = row_counter

    -- Private Methods

    -- Public Methods
    function self:display(ports)
        local COL_SEP = ZEROHI .. "|" .. NORMAL
        local totals = 0
        printf("%2d:%-20s", self.number, self.name)
        for _,p in ipairs(ports) do
            local v = p[struct][field]
            if type(v) == "number" then
                totals = totals + v
            else
                has_totals = false
            end
            printf("%s%10s", COL_SEP, tostring(v))
        end
        if has_totals then
            printf("%s%10d%s\n", COL_SEP, totals, ERASE_EOL)
        else
            printf(COL_SEP .. ERASE_EOL .. "\n")
        end
    end

    return self
end

local TrafficGen = {}
function TrafficGen.new()
    local self = {}
    --
    -- Private variables
    --
    local known_ports = {}
    local visible_ports = {}
    local default_ports = {}
    local known_rows = {}
    local is_running = true
    local is_frozen = false

    --
    -- Public variables
    --

    --
    -- Private Methods
    --

    -- Get the list of possible ports from the C code. Result is stored in
    -- known_ports
    local function get_possible_ports()
        local index = 0
        repeat
            local port_info = bdktrafficgen.port_get(index)
            if port_info then
                index = index + 1
                known_ports[index] = port_info
            end
        until (port_info == nil)
    end
    get_possible_ports()

    -- Convert a list of ports into a C port_set_t
    -- FIXME: Does the port_set_t get GC?
    local function get_port_set(range)
        local set = bdktrafficgen.port_set_t()
        for _,port in ipairs(range) do
            bdktrafficgen.port_add(set, port)
        end
        return set
    end

    -- Parse a port list string
    local function parse_port_list(str)
        assert(str:sub(1,1) == "p")
        local ports = {}
        local index = 2
        local start_num = nil
        while index <= #str do
            local num, sep = str:match("^(%d+)([,-]?)", index)
            if not num then
                error('Invalid port range "' .. str .. '"')
            end
            index = index + #num + #sep
            if sep == "-" then
                start_num = num
            else
                local stop_num = num
                if not start_num then
                    start_num = stop_num
                end
                for n=start_num, stop_num do
                    for _,port in ipairs(known_ports) do
                        if port.port == n then
                            table.insert(ports, port)
                            break
                        end
                    end
                end
                start_num = nil
            end
        end
        return ports
    end

    -- Parse a command line into a command, a port range, and arguments
    local function parse_command(str)
        local SPECIAL_WORDS = {["true"]=true, ["false"]=false, ["on"]=true, ["off"]=false}
        local command
        local ports = nil
        local args = {}
        for word in str:gmatch("[^ ]+") do
            if not command then
                command = "cmd_" .. word
            elseif (not ports) and (word == "all") then
                ports = known_ports
            elseif (not ports) and (word == "default") then
                ports = default_ports
            elseif (not ports) and (word:sub(1,1) == "p") then
                ports = parse_port_list(word)
            elseif SPECIAL_WORDS[word] ~= nil then
                table.insert(args, SPECIAL_WORDS[word])
            else
                table.insert(args, word)
            end
        end
        if ports == nil then
            ports = default_ports
        end
        return command, ports, args
    end

    -- Create commands for getting and setting each value in the port.setup
    -- structure.
    local function create_struct_commands(name, struct)
        -- SWIG struct have a ".get" meta field with a list of all structure members
        local meta = getmetatable(struct)
        local fields = meta[".get"]
        -- Add in sorted order
        for _,field_name in ipairs(table.sorted_keys(fields)) do
            -- Skip complex types and fields beginning with "_"
            if (type(struct[field_name]) ~= "userdata") and (field_name:sub(1,1) ~= '_') then
                self["cmd_" .. field_name] = function (self, port_range, args)
                    for _, port in pairs(port_range) do
                        if #args == 1 then
                            port[name][field_name] = args[1]
                        else
                            printf("Port %s: %s = %s\n", port.port, field_name, tostring(port[name][field_name]))
                        end
                    end
                end
                table.insert(known_rows, Row.new(field_name, name, field_name, true))
            end
        end
    end
    create_struct_commands("stats", known_ports[1].stats)
    create_struct_commands("setup", known_ports[1].setup)

    --
    -- Public Methods
    --

    -- Print a list of all commands
    function self:cmd_help(port_range, args)
        local commands = {}
        for k in pairs(self) do
            if k:sub(1,4) == "cmd_" then
                table.insert(commands, k:sub(5))
            end
        end
        table.sort(commands)
        for i,cmd in ipairs(commands) do
            printf("%-25s ", cmd)
            if i % 3 == 0 then
                printf("\n")
            end
        end
        printf("\n")
    end

    -- Select which ports to used by default
    function self:cmd_default(port_range, args)
        assert (#args == 0, "No arguments expected")

        default_ports = port_range

        printf("Default ports:")
        for _,port in ipairs(default_ports) do
            printf(" %d", port.port)
        end
        printf("\n")
    end

    -- Quit the main run() loop
    function self:cmd_quit(port_range, args)
        assert (#args == 0, "No arguments expected")
        is_running = false
    end

    function self:cmd_start(port_range, args)
        assert (#args == 0, "No arguments expected")
        bdktrafficgen.do_transmit(get_port_set(port_range))
    end

    function self:cmd_stop(port_range, args)
        assert (#args == 0, "No arguments expected")
        self:cmd_output_enable(port_range, {false})
    end

    function self:cmd_show(port_range, args)
        assert (#args == 0, "No arguments expected")
        -- FIXME: Do union
        visible_ports = port_range
    end

    function self:cmd_hide(port_range, args)
        assert (#args == 0, "No arguments expected")
        -- FIXME: Do intersection
        visible_ports = {}
    end

    function self:cmd_clear(port_range, args)
        assert (#args == 0, "No arguments expected")
        bdktrafficgen.do_clear(get_port_set(port_range))
    end

    function self:cmd_reset(port_range, args)
        assert (#args == 0, "No arguments expected")
        bdktrafficgen.do_reset(get_port_set(port_range))
    end

    function self:cmd_tx_percent(port_range, args)
        print "Not implemented"
    end

    function self:cmd_tx_rate(port_range, args)
        print "Not implemented"
    end

    function self:cmd_csr(port_range, args)
        print "Not implemented"
    end

    function self:cmd_row(port_range, args)
        print "Not implemented"
    end

    function self:cmd_hli(port_range, args)
        print "Not implemented"
    end

    function self:cmd_freeze(port_range, args)
        is_frozen = not is_frozen
    end

    function self:cmd_cls(port_range, args)
        assert (#args == 0, "No arguments expected")
        printf(ERASE_WIN .. GOTO_BOTTOM);
    end

    function self:cmd_reboot(port_range, args)
        assert (#args == 0, "No arguments expected")
        printf(SCROLL_FULL .. GOTO_BOTTOM)
        io.flush()
        octeon.c.bdk_reset_octeon()
    end

    function self:cmd_mii(port_range, args)
        print "Not implemented"
    end

    function self:cmd_speed(port_range, args)
        print "Not implemented"
    end

    function self:cmd_arp(port_range, args)
        print "Not implemented"
    end

    function self:cmd_find_max(port_range, args)
        print "Not implemented"
    end

    function self:cmd_scan_sizes(port_range, args)
        print "Not implemented"
    end

    function self:cmd_loopback(port_range, args)
        print "Not implemented"
    end

    function self:cmd_backpressure(port_range, args)
        print "Not implemented"
    end

    function self:cmd_alias(port_range, args)
        print "Not implemented"
    end

    function self:cmd_unalias(port_range, args)
        print "Not implemented"
    end

    function self:cmd_echo(port_range, args)
        pprint(table.unpack(args))
    end

    function self:cmd_type(port_range, args)
        print "Not implemented"
    end

    -- Issue a traffic gen comamnd line
    function self:command(command_line)
        local command, port_range, args = parse_command(command_line)
        if type(self[command]) ~= "function" then
            print("Invalid command")
        else
            local status, result = pcall(self[command], self, port_range, args)
            if status then
                return result
            else
                printf("ERROR: %s\n", result)
            end
        end
    end

    function self:display()
        if #visible_ports == 0 then
            return 0
        end

        local num_rows = 0
        printf(CURSOR_OFF .. GOTO_TOP)

        printf(ZEROHI .. "   %20s", "Port")
        for _,port in ipairs(visible_ports) do
            printf("|   Port %2d", port.port)
        end
        printf("|%10s%s\n%s", "Totals", ERASE_EOL, NORMAL);
        for _,row in ipairs(known_rows) do
            if row.visible then
                row:display(visible_ports)
                num_rows = num_rows + 1
            end
        end
        print("-------" .. ERASE_EOL)
        printf(ERASE_EOL .. "\n");

        printf(GOTO_BOTTOM .. CURSOR_ON)
        return num_rows
    end

    -- Run traffic gen interactively
    function self:run()
        is_running = true
        while is_running do
            -- Make sure the stats are updated
            bdktrafficgen.do_update()
            local num_rows = self:display()
            -- Confine scrolling region
            printf("\27[%d;r" .. GOTO_BOTTOM, num_rows + 3)
            -- Poll port status
            for _,port in ipairs(known_ports) do
                -- FIXME octeon.c.bdk_helper_link_autoconf(port.port)
            end

            printf("Command> ")
            local cmd = io.read()
            if cmd ~= "" then
                self:command(cmd)
            end
            printf(SCROLL_FULL)
        end
        printf(SCROLL_FULL .. GOTO_BOTTOM)
    end

    return self
end

octeon.c.bdk_init_cores(0);
TrafficGen.new():run()

return TrafficGen
