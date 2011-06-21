import pexpect
import tools

import test_config
import test_file
import test_flash
import test_ddr
import test_qlm
import test_pcie
import test_srio
import test_twsi
import test_smi
import test_gpio
import test_ilua
import test_net

child = tools.start_connection()
for test in tools.get_tests():
    test.run()

child.sendline("quit")
child.expect(pexpect.EOF)

