import os
import tools

def test(child):
    child.sendline("file")
    child.expect("File Menu")
    tools.send_menu(child, "view")
    child.expect("Enter filename: ")
    child.sendline(os.getenv("BDK_ROOT") + "/rom/full/init.lua")
    output = tools.send_menu(child, "hex")
    assert("Octeon Bringup and Diagnostic Kit" in output)
    assert("end" in output)
    child.expect("Enter filename: ")
    child.sendline(os.getenv("BDK_ROOT") + "/rom/full/init.lua")
    child.expect("Starting offset: ")
    child.sendline("0")
    child.expect("Bytes to display: ")
    child.sendline("32")
    output = tools.send_menu(child, "copy")
    assert("00000000: 0a2d2d20 5072696e 74206f75 74206120    .-- Print out a" in output)
    assert("00000010: 62616e6e 65720a70 72696e74 28222229    banner.print(\"\")" in output)
    child.expect("Enter source filename: ")
    child.sendline(os.getenv("BDK_ROOT") + "/rom/full/init.lua")
    child.expect("Enter destination filename: ")
    child.sendline("t.tmp")
    tools.send_menu(child, "rm")
    child.expect("Enter filename: ")
    child.sendline("foo")
    child.expect("ERROR: foo: No such file or directory")
    tools.send_menu(child, "rm")
    child.expect("Enter filename: ")
    child.sendline("t.tmp")
    tools.send_menu(child, "lua")
    child.expect("Enter filename: ")
    child.sendline("foo")
    child.expect("ERROR: cannot open foo: No such file or directory")
    tools.send_menu(child, "bin")
    child.expect("Enter filename: ")
    child.sendline("foo")
    child.expect("ERROR: File does not support mmap()")
    tools.send_menu(child, "uboot")
    child.expect("Enter filename for Uboot: ")
    child.sendline("foo")
    child.expect("foo: No such file or directory")
    tools.send_menu(child, "quit")

tools.add_test(test, "File")

