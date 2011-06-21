import tools

def test(child):
    child.sendline("srio")
    child.expect("SRIO Menu")
    tools.send_menu(child, "quit")

tools.add_test(test, "SRIO")
