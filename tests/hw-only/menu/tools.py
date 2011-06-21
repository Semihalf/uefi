import sys
import os
import pexpect

MENU_PROMPT = "Menu choice \[\]: "
_BANNER = "###############################################################"
_test_list = []
_child_cnx = None

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
    global _child_cnx
    assert os.getenv("BDK_ROOT"), "BDK_ROOT not defined"
    assert os.getenv("OCTEON_REMOTE_CONSOLE"), "OCTEON_REMOTE_CONSOLE not defined"
    _child_cnx = pexpect.spawn("bdk-lua -l coverage " + os.getenv("BDK_ROOT") + "/rom/main.lua")
    _child_cnx.logfile = sys.stdout
    #_child_cnx.logfile = file("menu_automate.log", "w")
    _child_cnx.setecho(False)
    wait_for_main_menu(_child_cnx)
    _child_cnx.sendline("")
    wait_for_main_menu(_child_cnx)
    _child_cnx.sendline("keys")
    wait_for_main_menu(_child_cnx)
    return _child_cnx

class Test:
    def __init__(self, test_func, description):
        self.test_func = test_func
        self.description = description
    def run(self):
        print _BANNER
        print "Starting test " + self.description
        print _BANNER
        self.test_func(_child_cnx)
        wait_for_main_menu(_child_cnx)
        print
        print _BANNER
        print "Complete test " + self.description
        print _BANNER

def add_test(test, description=""):
    global _test_list
    _test_list.append(Test(test, description))

def get_tests():
    return _test_list
