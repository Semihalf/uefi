import sys
import os
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

for test in [test_config.test, test_file.test, test_flash.test, test_ddr.test,
             test_qlm.test, test_pcie.test, test_srio.test, test_twsi.test,
             test_smi.test, test_gpio.test, test_ilua.test, test_net.test]:
    test(child)
    tools.wait_for_main_menu(child)

child.sendline("quit")
child.expect(pexpect.EOF)

