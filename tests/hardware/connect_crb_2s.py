#!/usr/bin/python

import re
import sys
import os
import select
import time

class Connection:
    def __init__(self, console="/dev/ttyUSB2", mcu="/dev/ttyUSB3", logname="test.log"):
        # Set the baud rate of the serial ports
        baudrate=115200
        if os.system("stty --file=" + console + " " + str(baudrate)):
            raise Exception("stty failed")
        baudrate=9600
        if os.system("stty --file=" + mcu + " " + str(baudrate)):
            raise Exception("stty failed")
        # Open the serial ports
        fd_console = os.open(console, os.O_RDWR | os.O_SYNC | os.O_NDELAY)
        fd_mcu = os.open(mcu, os.O_WRONLY | os.O_SYNC | os.O_NDELAY)

        self.logging = Log(logname)
        self.fd_console = fd_console
        self.fd_mcu = fd_mcu
        self.poll = select.poll()
        self.poll.register(self.fd_console, select.POLLIN)
        try:
            self.waitfor("JUNK", timeout=0)
        except:
            pass
    def close(self):
        os.write(self.fd_mcu, "\r\nF7\r\n")
        self.logging.close()

    def write(self, data):
        self.logging.logInput(data)
        os.write(self.fd_console, data)
        #os.fsync(self.fd_console);

    def read(self, timeout):
        while 1:
            ready = self.poll.poll(timeout * 1000)
            if ready:
                result = os.read(self.fd_console, 1)
                if result != "\r":
                    break
            else:
                self.logging.flush()
                raise Exception("Timeout")
        self.logging.logOutput(result)
        return result

    def log(self, data):
        self.logging.logInfo(data)

    def send(self,str):
        self.write(str + "\r")

    def sendEcho(self,str):
        self.logging.logInput(str)
        for c in str:
            os.write(self.fd_console, c)
            r = self.read(1)
            while (c != r):
                r = self.read(1)
            if c != r:
                try:
                    self.waitfor("JUNK", timeout=1)
                except:
                    pass
                self.logging.flush()
                raise Exception("Send wasn't echoed properly. Sent '%s', received '%s'" % (c, r))
        os.write(self.fd_console, "\r")

    def waitfor(self, str, timeout=5):
        complete = ""
        current = ""
        while not re.search(str, current):
            current+=self.read(timeout)
            if len(current) > 512:
                complete += current[0:256]
                current = current[256:]
        return complete + current

    def delay(self, timeout):
        try:
            self.waitfor("ANY PENDING DATA", timeout)
        except:
            pass

    def powerCycle(self):
        self.log("Power cycle board")
        os.write(self.fd_mcu, "F7\r\n")
        time.sleep(7)
        os.write(self.fd_mcu, "N7\r\n")
        time.sleep(3)
        os.write(self.fd_mcu, "N8\r\n")
        time.sleep(1)
        os.write(self.fd_mcu, "F8\r\n")
        time.sleep(1)

    def match(self, correct, timeout=5):
        correct = correct.strip()
        r = self.read(timeout)
        while r in " \r\n\b":
            r = self.read(timeout)
        current = r
        for c in correct:
            if r != c:
                try:
                    self.waitfor("ANY PENDING DATA", timeout=1)
                except:
                    pass
                self.logging.flush()
                raise Exception("Match failed\nCorrect: \"" + correct + "\"\nRead: \"" + current + "\"\n")
            r = self.read(timeout)
            current += r

    def matchRegExp(self, correct, timeout=5):
        print "Not supported"


class Log:
    def __init__(self, filename):
        self.file = open(filename, "w")
        self.outputbuf = ""

    def close(self):
        self.flush()
        self.file.close()

    def flush(self):
        if self.outputbuf:
            if self.outputbuf[-1] != "\n":
                self.outputbuf += "\n"
            for l in self.outputbuf[0:-1].split("\n"):
                self.file.write(">>> " + l + "\n")
                print ">>> " + l
            self.outputbuf = ""
        self.file.flush();

    def _write(self, data):
        self.flush()
        self.file.write(data)

    def logInput(self, data):
        self._write("<<< " + data + "\n")
        print "<<< " + data

    def logOutput(self, data):
        self.outputbuf += data
        if data == "\n":
            self.flush()

    def logInfo(self, data):
        self._write("*** " + data + "\n")
        print "*** " + data

