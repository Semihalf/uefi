import tools

def test(child):
    child.sendline("config")
    child.expect("Configuration Menu")
    r = tools.send_menu(child, "item33")
    assert("MAC address (0x20fb7" in r)
    child.expect("MAC address: ")
    child.sendline("")
    child.expect("User interrupted input")
    tools.send_menu(child, "quit")


