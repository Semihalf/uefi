import sys
import os
import pexpect

MENU_PROMPT = "Menu choice \[\]: "

def wait_for_main_menu(child):
    child.expect("Main Menu")
    child.expect("Exit menu")
    child.expect(MENU_PROMPT)

def send_menu(child, line):
    child.expect("=================================")
    result = child.before + child.after
    child.expect(MENU_PROMPT)
    result += child.before + child.after
    child.sendline(line)
    return result

def start_connection():
    assert os.getenv("BDK_ROOT"), "BDK_ROOT not defined"
    assert os.getenv("OCTEON_REMOTE_CONSOLE"), "OCTEON_REMOTE_CONSOLE not defined"
    child = pexpect.spawn("bdk-lua -l coverage " + os.getenv("BDK_ROOT") + "/rom/main.lua")
    child.logfile = sys.stdout
    #child.logfile = file("menu_automate.log", "w")
    child.setecho(False)
    wait_for_main_menu(child)
    child.sendline("")
    wait_for_main_menu(child)
    child.sendline("keys")
    wait_for_main_menu(child)
    return child

