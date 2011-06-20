import tools

def test(child):
    child.sendline("gpio")
    child.expect("GPIO Menu")
    tools.send_menu(child, "quit")

