#!/usr/bin/python

import re
import sys
import os
import select
import time
import telnetlib

#
# Log file implementation
#
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

#
# Implements a serial port connection. Used by GenericPort
#
class SerialPort:
    def __init__(self, connect_str):
        parts = connect_str.split(":")
        self.device = parts[0]
        if len(parts) == 2:
            baudrate = int(parts[1])
        else:
            baudrate = 115200
        if os.system("stty --file=%s %d raw clocal -crtscts -echo" % (self.device, baudrate)):
            raise Exception("stty failed")
        self.fd = os.open(self.device, os.O_RDWR | os.O_SYNC | os.O_NDELAY)
        self.poll = select.poll()
        self.poll.register(self.fd, select.POLLIN)

    def close(self):
        os.close(self.fd)

    def write(self, data):
        os.write(self.fd, data)

    def readChar(self, timeout):
        ready = self.poll.poll(timeout * 1000)
        if ready:
            return os.read(self.fd, 1)
        else:
            raise Exception("Timeout")

#
# Implements a telnet connection. Used by GenericPort
#
class TelnetPort:
    def __init__(self, connect_str):
        parts = connect_str.split(":")
        assert len(parts) == 2, "Expected 'host:port'"
        self.host = parts[0]
        self.port = int(parts[1])
        self.telnet = telnetlib.Telnet(self.host, self.port)
        self.telnet.read_until("JUNK", timeout=1)
        self.data = ""

    def close(self):
        self.telnet.close()

    def write(self, data):
        self.data += self.telnet.read_eager()
        if len(self.data) > 256:
            self.data = self.data[-256:]
        self.telnet.write(data)

    def readChar(self, timeout):
        start_time = time.time()
        while not self.data:
            if time.time() - start_time > timeout:
                raise Exception("Timeout")
            self.data += self.telnet.read_eager()
        result = self.data[0]
        self.data = self.data[1:]
        return result

#
# Port connection for scripting
#
class GenericPort:
    def __init__(self, connect_str, logObject):
        self.connect_str = connect_str
        if "/" in connect_str:
            self.port = SerialPort(connect_str)
        else:
            self.port = TelnetPort(connect_str)
        self.log = logObject
        self.log.logInfo("Connected to %s" % connect_str)

    def close(self):
        self.port.close()
        self.log.logInfo("Connection %s closed" % self.connect_str)

    def write(self, data):
        self.log.logInput(data)
        self.port.write(data)

    def readChar(self, timeout):
        data = self.port.readChar(timeout)
        if data == "\033":
            data = "<ESC>"
        self.log.logOutput(data)
        return data

    def send(self,str):
        self.write(str + "\r")

    def sendEcho(self,str):
        self.log.logInfo("Send echo: " + str)
        for c in str:
            self.port.write(c)
            r = self.readChar(1)
            while (c != r):
                r = self.readChar(1)
            if c != r:
                try:
                    self.waitfor("JUNK", timeout=1)
                except:
                    pass
                raise Exception("Send wasn't echoed properly. Sent '%s', received '%s'" % (c, r))
        self.port.write("\r")

    def delay(self, timeout):
        try:
            self.waitfor("ANY PENDING DATA", timeout)
        except:
            pass

    def waitfor(self, str, timeout=1):
        complete = ""
        current = ""
        start_time = time.time()
        while not str in current:
            current += self.readChar(timeout)
            if len(current) > 512:
                complete += current[0:256]
                current = current[256:]
            if time.time() - start_time > timeout:
                raise Exception("Timeout")
        return complete + current

    def waitforRE(self, str, timeout=1):
        complete = ""
        current = ""
        regex = re.compile(str)
        start_time = time.time()
        while not regex.search(current):
            current += self.readChar(timeout)
            if len(current) > 512:
                complete += current[0:256]
                current = current[256:]
            if time.time() - start_time > timeout:
                raise Exception("Timeout")
        return complete + current

    def match(self, correct, timeout=1):
        correct = correct.strip()
        r = self.readChar(timeout)
        while r in " \r\n\b":
            r = self.readChar(timeout)
        current = r
        for c in correct:
            if r != c:
                try:
                    self.waitfor("ANY PENDING DATA", timeout=1)
                except:
                    pass
                raise Exception("Match failed\nCorrect: \"" + correct + "\"\nRead: \"" + current + "\"\n")
            r = self.readChar(timeout)
            current += r

    def matchRE(self, correct, timeout=1):
        r = self.readChar(timeout)
        while r in " \r\n\b":
            r = self.readChar(timeout)
        current = r
        regex = re.compile(correct)
        start_time = time.time()
        match = regex.match(current)
        while not match:
            current += self.readChar(timeout)
            if time.time() - start_time > timeout:
                break
            match = regex.match(current)
        if match:
            return match
        if current:
            raise Exception("RE match failed \"%s\", got \"%s\"" % (correct, current))
        else:
            raise Exception("Timeout matching RE \"%s\"" % correct)

