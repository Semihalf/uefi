import tools

def test(child):
    child.sendline("pcie")
    child.expect("PCIe Menu")
    tools.send_menu(child, "quit")

tools.add_test(test, "PCIe")
