#!/usr/bin/python

import sys
import os
import time
import traceback
import connection

#
# Generic connection for a board. Serves as a base class for specific boards
# below
#
class Board:
    def __init__(self, console, logObject):
        self.logging = logObject
        self.console = connection.GenericPort(console, self.logging)

    def close(self):
        self.console.close()

    def write(self, data):
        self.console.write(data)

    def log(self, data):
        self.logging.logInfo(data)

    def send(self,str):
        self.console.send(str)

    def sendEcho(self,str):
        self.console.sendEcho(str)

    def waitfor(self, str, timeout=5):
        return self.console.waitfor(str, timeout)

    def waitforRE(self, str, timeout=5):
        return self.console.waitforRE(str, timeout)

    def delay(self, timeout):
        return self.console.delay(timeout)

    def match(self, correct, timeout=5):
        return self.console.match(correct, timeout)

    def matchRE(self, correct, timeout=5):
        return self.console.matchRE(correct, timeout)

    def runTestLoop(self, test_func):
        # Runs a test, defined in "test_func", in an infinite loop tracking pass
        # and fail statistics. The test is given one argument, the connection
        # instance.
        count = 0
        pass_count = 0
        fail_count = 0
        while True:
            count += 1
            print "Starting loop %d: Pass %d, Fail %d" % (count, pass_count, fail_count)
            try:
                test_func(self)
                pass_count += 1
            except (KeyboardInterrupt, SystemExit):
                self.log("Abort forced during loop %d: Pass %d, Fail %d" % (count, pass_count, fail_count))
                raise
            except:
                fail_count += 1
                ex_str = traceback.format_exc()
                try:
                    self.waitfor("JUNK", timeout=1)
                except:
                    pass
                self.log("FAIL: Exception: %s" % ex_str)
            self.log("After loop %d: Pass %d, Fail %d" % (count, pass_count, fail_count))

#
# Class for controlling EBB and EVB boards with MCUs that control power cycling
# and reset
#
class Board_EVB(Board):
    def __init__(self, console, mcu, mcu2, logObject):
        Board.__init__(self, console, logObject)
        self.mcu = connection.GenericPort(mcu, logObject)
        if mcu2:
            self.mcu2 = connection.GenericPort(mcu2, logObject)
            self.multinode = True
        else:
            self.mcu2 = None
            self.multinode = False

    def close(self):
        self.mcu.close()
        if self.mcu2:
            self.mcu2.close()
        Board.close(self)

    def powerCycle(self):
        self.log("Power cycle board")
        mcu_list = [self.mcu]
        if self.mcu2:
            mcu_list.append(self.mcu2)
        for m in mcu_list:
            try:
                self.mcu.waitfor("JUNK")
            except:
                pass
        for m in mcu_list:
            m.sendEcho("echo mcu_responded")
            m.match("mcu_responded")
            m.waitforRE("EBB88.. MCU Command>")
            m.sendEcho("P -f -r")
        for m in mcu_list:
            m.waitforRE("EBB88.. MCU Command>", timeout=15)

#
# Class for controlling the CRB-2S. Requires an serial relay box for control
#
class Board_CRB_2S(Board):
    def __init__(self, console, bmc, logObject):
        Board.__init__(self, console, logObject)
        self.bmc = bmc
        self.multinode = True

    def close(self):
        Board.close(self)

    def powerCycle(self):
        self.log("Power cycle board")
        os.system("ipmitool -H %s -U admin -P admin power cycle" % self.bmc)

def parseArgs():
    try:
        assert len(sys.argv) >= 2 # Remember 0 is program name
        if ("/" in sys.argv[1]) or (":" in sys.argv[1]):
            # Using either serial ports, or telnet with port number specified
            # Need at least two arguments (console, mcu/control)
            assert len(sys.argv) >= 3
            console = sys.argv[1]
            mcu1 = sys.argv[2]
            # Third optional is for mcu2 in two node setup
            if len(sys.argv) >= 4:
                mcu2 = sys.argv[3]
            else:
                mcu2 = None
        elif sys.argv[1] == "sol":
            # Use Serial Over Lan. The second argument must be a BMC nmae or IP
            assert len(sys.argv) == 3
            console = "sol:%s" % sys.argv[2]
            mcu1 = sys.argv[2]
            mcu2 = None
        else:
            # Using telnet with a hostname. Assume it is the name of a MCU
            # and the ports are 9761 and 9760
            console = sys.argv[1] + ":9761"
            mcu1 = sys.argv[1] + ":9760"
            if len(sys.argv) >= 3:
                mcu2 = sys.argv[2] + ":9760"
            else:
                mcu2 = None
        print "Console connection:     %s" % console
        print "MCU/control connection: %s" % mcu1
        print "Second MCU connection:  %s" % mcu2
        return (console, mcu1, mcu2)
    except:
        print
        print "Test script for controlling boards remotely"
        print
        print "Usage:"
        print "  SCRIPT host [host2]"
        print "    host = MCU host name where the console is port 9761 and MCU is 9760"
        print "    host2 = MCU host name for second board in dual node setup (Optional)"
        print
        print "  SCRIPT host:port host2:port2 [host3:port3]"
        print "    host:port = Telnet to this host and port conencts to console"
        print "    host2:port2 = MCU/control of board"
        print "    host3:port3 = MCU of second board in dual node setup (Optional)"
        print
        print "  SCRIPT /dev/ttyUSB1 /dev/ttyUSB2 [/dev/ttyUSB3]"
        print "    /dev/ttyUSB1 = Direct serial connection to the console"
        print "    /dev/ttyUSB2 = MCU/control of board"
        print "    /dev/ttyUSB3 = MCU of second board in dual node setup (Optional)"
        print
        print "  SCRIPT sol bmc"
        print "    sol = Keyword to use ipmitool for console"
        print "    bmc = BMC host name ir IP address"
        print
        print "  In EBB / EVB setups, control uses commands to the MCU"
        print "  In CRB-2S, host2 should be the IP address or hostname of the BMC"
        sys.exit(2)
