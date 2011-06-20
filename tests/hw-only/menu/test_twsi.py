import tools

def test(child):
    child.sendline("twsi")
    child.expect("TWSI Menu")
    tools.send_menu(child, "quit")

