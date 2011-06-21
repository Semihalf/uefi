import tools

def test(child):
    child.sendline("ddr")
    child.expect("DDR Menu")
    tools.send_menu(child, "quit")

tools.add_test(test, "DDR")
