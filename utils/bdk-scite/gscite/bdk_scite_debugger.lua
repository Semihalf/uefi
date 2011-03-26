--
-- SciTE startup script for the BDK debugger
--

require("strict")
require("utils")

local MARKER_BREAK = 2      -- Marker to use for breakpoints
local MARKER_CURRENT = 3    -- Marker to use for current line

local debug_process = nil   -- Handle to the debugger process
local debug_commands = {}   -- Pending command to be sent to the debugger
local gui_lvar = nil        -- Handle to the GUI list of variables
local gui_lbt = nil         -- Handle to the GUI list for backtrace

--
-- Create the GUI the SciTE sidebar. This should only be called once
--
local function create_gui()
    assert(bdk_gui_page_control, "Handle for GUI not found")
    local page_control = bdk_gui_page_control
    local debug_tab = page_control:Add_Page("Lua Debug")
    -- Backtrace
    gui_lbt = ListView.new(0)
    gui_lbt:Add_Column("Backtrace")
    -- Local variables
    gui_lvar = ListView.new(0)
    gui_lvar:Add_Column("Local")
    gui_lvar:Add_Column("Value")
    -- Splitter
    local spl = Splitter.new(debug_tab, true)
    spl:Set_Clients(gui_lbt, gui_lvar)
    -- Buttons
    local btn=Button.new(debug_tab, "Step Into")
    btn:on_Click(command_step)
    local btn=Button.new(debug_tab, "Step Over")
    btn:on_Click(command_next)
    local btn=Button.new(debug_tab, "Continue")
    btn:on_Click(command_continue)
    local btn=Button.new(debug_tab, "Break")
    btn:on_Click(command_interrupt)
    local btn=Button.new(debug_tab, "Quit Debugger")
    btn:on_Click(command_quit)
end

local function create_markers()
    editor:MarkerDefine(MARKER_BREAK, 0)
    editor:MarkerSetBack(MARKER_BREAK, 0x0000ff) -- Blue, Green, Red
    editor:MarkerDefine(MARKER_CURRENT, 2)
    editor:MarkerSetBack(MARKER_CURRENT, 0x00ff00) -- Blue, Green, Red
end

--
-- Clear out GUI state. Used to empty GUI before any commands
-- or when the debugger terminates.
--
local function clear_gui()
    gui_lvar:Clear()
    gui_lbt:Clear()
    editor:MarkerDeleteAll(MARKER_CURRENT)
    editor:MarkerDeleteAll(MARKER_BREAK)
end

--
-- Issue a command to the debugger. Commands are executed
-- Every time the debug prompt is seen. This function simply
-- enqueues the command for a future prompt.
--
local function issue_command(cmd)
    if #debug_commands == 0 then
        -- Do nothing command to force the prompt to show again
        debug_process:write("gui off\n")
    end
    table.insert(debug_commands, cmd)
end

--
-- Debugger output FIXME
--
local function process_name_value(name, value)
    local base, number = string.match(name, "(%a+)(%d*)")
    number = tonumber(number)
    if base == "Backtrace" then
        gui_lbt:Add_Item(value)

    elseif base == "Local" then
        local name, value = string.match(value, "(%a+) (.*)")
        local row = gui_lvar:Add_Item(name)
        gui_lvar:Set_Item(row, 1, value)

    elseif base == "Breakpoint" then
        local filename = props["FilePath"]
        local file, lineno = string.match(value, "([^:]+):(%d+)")
        if file == filename then
            lineno = tonumber(lineno)
            editor:MarkerAdd(lineno - 1, MARKER_BREAK)
        end

    elseif base == "Stackframe" then
        local v = tonumber(value)

    elseif base == "File" then
        local filename = props["FilePath"]
        if value ~= filename then
            print("Switching to file " .. value)
            scite.Open(value)
        end

    elseif base == "Line" then
        local lineno = tonumber(value)
        editor:MarkerAdd(lineno - 1, MARKER_CURRENT)
        editor:GotoLine(lineno - 1)
    end
end

--
-- This function is called whenever SciTE receives data from the
-- debug process. The data tends to be in large chunks and not divided
-- by lines.
--
-- This function must be global
--
function debug_data_in(data)
    for k,v in string.gmatch(data, "(%w+):%s*([^\n\r]+)") do
        process_name_value(k, v)
    end
    --print(data)
    if #data >= 5 then
        -- If we received a prompt then we need to process the next
        -- pending command
        if data:sub(-5) == "dbg> " then
            local cmd = table.remove(debug_commands, 1)
            if cmd then
                debug_process:write(cmd .. "\n")
            else
                print("Program is stopped")
            end
        end
    end
end

--
-- Called when the debugger process dies
--
-- This function must be global
--
function debug_died(status)
    print("Debugger terminated")
    clear_gui()
    debug_process = nil
    debug_commands = {}
end

--
-- Issue a user command to the debugger. It automatically
-- adds the commands to update the GUI state after the command
-- is issued.
--
local function issue_user_command(description, command)
    if debug_process then
        print(description)
        issue_command(command)
        clear_gui()
        issue_command("bt")
        issue_command("locals")
        issue_command("where")
        issue_command("b")
    else
        print("Debugger not running")
    end
end

--
-- This function is called to initially start debugging a script
--
-- This function must be global
--
function command_debug(unused)
    local filename = props["FilePath"]
    assert(debug_process == nil, "Debugger is already running")
    create_markers()
    local command = 'bdk-debug -nogui "' .. filename .. '"'
    for i = 1,4 do
        local p = props[tostring(i)]
        if p ~= "" then
            command = command .. ' "' .. p .. '"'
        else
            break
        end
    end
    print("Starting debugger")
    print(command)
    debug_process = spawner.new(command)
    debug_process:set_output('debug_data_in')
    debug_process:set_result('debug_died')
    debug_process:run()
    issue_command("bt")
    issue_command("locals")
    issue_command("where")
    issue_command("b")
end

--
-- Function to forcibly kill the debug process. Should only be used
-- if the debugger is hung
--
-- This function must be global
--
function command_kill()
    if debug_process then
        debug_process:kill()
    end
end

--
-- Send interrupt (^C) to debugger
--
function command_interrupt()
    if debug_process then
        print("Sending break")
        local p = spawner.new("killall -s SIGINT bdk-lua")
        p:run()
    else
        print("Debugger not running")
    end
end

--
-- Toggle a breakpoint
--
function command_toggle_breakpoint()
    local filename = props["FilePath"]
    local lineno = editor:LineFromPosition(editor.CurrentPos)
    if editor:MarkerGet(lineno) == 2^MARKER_BREAK then
        issue_command("db " .. filename .. ":" .. tostring(lineno+1))
    else
        issue_command("b " .. filename .. ":" .. tostring(lineno+1))
    end
    issue_command("b")
end

--
-- Short functions to wrap user commands to the debugger
--
-- These functions must be global
--
function command_step() issue_user_command("Step into", "s") end
function command_next() issue_user_command("Step over", "n") end
function command_continue() issue_user_command("Continue", "c") end
function command_quit() issue_user_command("Quit", "quit") end

--
-- Create the GUI and add the commands to the tool menu
--
create_gui()
add_command("Start Debugger", "command_debug", "Ctrl+F5")
add_command("Kill Debugger", "command_kill")
add_command("Toggle Breakpoint", "command_toggle_breakpoint", "F9")

