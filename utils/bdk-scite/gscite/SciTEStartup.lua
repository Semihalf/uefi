--
-- SciTE startup script for use with the BDK
--
-- This script defines some extensions for SciTE to make it easier
-- to develop Lua scripts using the BDK. Some of the extend features
-- are:
--
-- 1) Load the "spawner" module from scite-debug. This module
--	gives  scripts process control.
-- X) FIXME
--

-- Add the BDK package path to SciTE's search path
BDK_ROOT = os.getenv("BDK_ROOT")
-- print("BDK is installed at " .. BDK_ROOT)
package.path = package.path .. ";" .. BDK_ROOT .. "/rom/?.lua"

-- Load modules that make programing easier
require("strict")
require("utils")

-- Load the process spawner shared library
local home = props["SciteDefaultHome"]
local open_fn = assert(package.loadlib(home.. "/unix-spawner-ex.so", "luaopen_spawner"))
open_fn()

-- Load the GUIshared library
local open_fn = assert(package.loadlib(home.. "/gui.so", "luaopen_gui"))
open_fn()

-- 
-- This function adds a GLOBAL Lua function to the Tools menu
-- caption = String to use as the Tools menu text
-- lua_function = String name of the function to call when chosen
--
local last_command = 0
local function add_command(caption, lua_function)
    props["command.name.%d.*.lua" % last_command] = caption
    props["command.subsystem.%d.*.lua" % last_command] = 3
    props["command.%d.*.lua" % last_command] = lua_function .. " $(FileNameExt)"
    last_command = last_command + 1
end

function command_debug(filename)
    print("Sorry, not implemented yet")
end
add_command("Debug", "command_debug")

print("Loaded BDK customization extensions SciTE")

-- Initialize the GUI sidebar
local sidebar = scite.GetSidebarHandle() 
gui.InitSidebar(sidebar)

--PageControl
local pc=PageControl.new(sidebar)
local pc1tab1=pc:Add_Page("1st Page")
local pc1tab2=pc:Add_Page("2nd Page")
local pc1tab3=pc:Add_Page("3rd Page")

function tab_change(selected)
  print("PageControl changed to Tab #"..selected)
end
pc:on_Change(tab_change)

--Listview
local lv=ListView.new(0)
lv:Add_Column("Col 1")
lv:Add_Column("Col 2")
local row
row=lv:Add_Item("Item1")
lv:Set_Item(row,1,"i1c2")
row=lv:Add_Item("Item2")
lv:Set_Item(row,1,"i2c2")

function lv_dblclick(selected)
  print("Listview Doubleclick on Item #"..selected)
end
lv:on_DblClick(lv_dblclick)

--Popup
local p=Popup.new(lv)
function menu_test1()
  print("Menuitem1 :)")
end

function menu_test2()
  print("Menuitem2 :)")
end

function menu_test3()
  print("Menuitem3 :)")
end

p:Add_Item("test1",menu_test1)
p:Add_Item("test2",menu_test2)
p:Add_Item("",0)
p:Add_Item("test3",menu_test3)

--RadioGroup
local rg=RadioGroup.new(0,"1st choice")
rg:Add_Item("2nd choice")
rg:Add_Item("3rd choice")
function rg_change(selected)
  print("Radiogroup changed to Item #"..selected)
end
rg:on_Change(rg_change)

--Splitter
local spl=Splitter.new(pc1tab1,true)
spl:Set_Clients(lv,rg)

--checkgroup
local cg=CheckGroup.new(pc1tab1,"1st option")
cg:Add_Item("2nd option")
cg:Add_Item("3rd option")
function cg_change(selected)
  print("Checkgroup-Item #"..selected.." changed!")
end
cg:on_Change(cg_change)

local edit=Edit.new(pc1tab1,"Text: ")
local memo=Memo.new(pc1tab1)

--Button
local btn=Button.new(pc1tab1,"Test-Button")
function btn_click()
  print("Button clicked!")
  print("Edit-Text: "..edit:Get_Text())
end
btn:on_Click(btn_click)

--Buttons for Message-Dialogs
local btn_err=Button.new(sidebar, "Show Error-Message")

function errorbutton_clicked()
  gui.Show_Error("Exception","something went wrong :(")
end
btn_err:on_Click(errorbutton_clicked)--button,evClick,function

local btn_info=Button.new(sidebar, "Show Info-Message")

function infobutton_clicked()
  gui.Show_Info("Information","something interesting...\nradiogroup's selected item is #"..rg:Get_Checked())
  print(memo:Get_Text())
end
btn_info:on_Click(infobutton_clicked)--button,evClick,function

local btn_warn=Button.new(sidebar, "Show Warning-Message")

function warnbutton_clicked()
  if cg:Is_Checked(0) then
    gui.Show_Warning("Alert","Beware, first Item in Checkgroup is selected! :D\n")
  else
    gui.Show_Warning("Alert","Beware, first Item in Checkgroup is NOT selected! :D\n")
  end
end
btn_warn:on_Click(warnbutton_clicked)--button,evClick,function

local btn_question=Button.new(sidebar, "Show Question-Messagebox")

function questionbutton_clicked()
  if gui.Show_Question("question","Do you really want to do this (clear Listview)?") then
    lv:Clear()
  end
end
btn_question:on_Click(questionbutton_clicked)

print("done")