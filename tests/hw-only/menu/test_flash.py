import tools

def test(child):
    child.sendline("flash")
    child.expect("Flash Menu")
    tools.send_menu(child, "init")
    child.expect("NOR Flash 0:Base address:  0x800100001f400000")
    child.expect("Vendor:        0x0002")
    child.expect("16 bit:        yes")
    child.expect("Size:          8388608 bytes")
    child.expect("Num regions:   2")
    child.expect("Erase timeout: 13107200000 cycles")
    child.expect("Write timeout: 819200 cycles")
    child.expect("Region 0: offset 0x0, 127 blocks, 65536 bytes/block")
    child.expect("Region 1: offset 0x7f0000, 8 blocks, 8192 bytes/block")
    tools.send_menu(child, "view(CS0)")
    child.expect("Starting offset: ")
    child.sendline("0")
    child.expect("Bytes to display: ")
    child.sendline("64")
    child.expect("00000000: ")
    child.expect("00000010: ")
    child.expect("00000020: ")
    child.expect("00000030: ")
    tools.send_menu(child, "write(CS0)")
    child.expect("Enter source filename: ")
    child.sendline("foo")
    child.expect("Flash offset: ")
    child.sendline("0")
    child.expect("foo: No such file or directory")
    tools.send_menu(child, "quit")

