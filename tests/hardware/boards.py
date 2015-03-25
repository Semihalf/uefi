#!/usr/bin/python

import time
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
    def __init__(self, console, serialbox, logObject):
        Board.__init__(self, console, logObject)
        self.serialbox = connection.GenericPort(serialbox, logObject)
        self.multinode = True

    def close(self):
        self.serialbox.close()
        Board.close(self)

    def powerCycle(self):
        self.log("Power cycle board")
        self.serialbox.send("F8")
        time.sleep(7)
        self.serialbox.send("N8")
        time.sleep(5)
        self.serialbox.send("N7")
        time.sleep(1)
        self.serialbox.send("F7")
        time.sleep(1)

