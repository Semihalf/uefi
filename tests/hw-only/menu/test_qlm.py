import tools

def test(child):
    child.sendline("qlm")
    child.expect("QLM Menu")
    tools.send_menu(child, "qlm0")
    child.expect("QLM0 Menu")
    tools.send_menu(child, "show")
    child.expect("QLM0 Mode: ")
    child.expect("QLM0 Gbaud: ")
    tools.send_menu(child, "clock")
    child.expect("QLM0 Clock: ")
    tools.send_menu(child, "read")
    child.expect("Lane \(0 - 3\): ")
    child.sendline("0")
    child.expect("Field: ")
    child.sendline("rx_eq_gen2")
    child.expect("QLM0 rx_eq_gen2\[0\]: 10 \(0x000a\)")
    tools.send_menu(child, "write")
    child.expect("Lane \(0-3, -1 for all\): ")
    child.sendline("-1")
    child.expect("Field: ")
    child.sendline("rx_eq_gen2")
    child.expect("Value: ")
    child.sendline("0xa")
    tools.send_menu(child, "dump")
    child.expect("Field")
    child.expect("Lane 0")
    child.expect("Lane 1")
    child.expect("Lane 2")
    child.expect("Lane 3")
    child.expect("rx_eq_gen2")
    child.expect("10 \(0x000a\)")
    child.expect("10 \(0x000a\)")
    child.expect("10 \(0x000a\)")
    child.expect("10 \(0x000a\)")
    tools.send_menu(child, "quit")
    tools.send_menu(child, "quit")

