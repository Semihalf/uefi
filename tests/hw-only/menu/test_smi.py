import tools

def test(child):
    child.sendline("smi")
    child.expect("SMI/MDIO Menu")
    tools.send_menu(child, "quit")

