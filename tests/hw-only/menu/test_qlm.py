import tools

def test(child):
    child.sendline("qlm")
    child.expect("QLM Menu")
    tools.send_menu(child, "quit")

