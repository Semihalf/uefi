import re
import sys
import os
import select
import time
import serial
import network

#
# Convert a string into another string where all escape codes and unprintable
# characters are in the form "\xx". This makes the string safe to display to
# the user. The user can then see if normally unprintable characters are in
# the original string.
#
def escapeString(str):
    output = []
    for c in str:
        b = ord(c)
        if (c == '"') or (b < 32) or (b > 126):
            output.append("\\%02x" % b)
        else:
            output.append(c)
    return "".join(output)

#
# Create a connection to a remote object through either serial or TCP. The
# connection supports multiple methods to help scripting the remote object.
#
class Connection:
    # Create a new connection. You can have any number open at a time
    def __init__(self, connect_string):
        if "/" in connect_string:
            # Assume serial is always device files
            serial.SerialConnection(self, connect_string)
        else:
            network.NetworkConnection(self, connect_string)
        assert self.fileno >= 0, "Failed to open connection"
        self.poll = select.poll()
        self.poll.register(self.fileno, select.POLLIN)

    # Close a connection
    def close(self):
        os.close(self.fileno)

    # Send RAW data over the connection
    def write(self, data):
        print ">>> \"%s\"" % escapeString(data)
        os.write(self.fileno, data)

    # Use a printf style function to send data
    def printf(self, data, *args):
        self.write(data % args)

    # Read a single RAW byte. Should normally not be used directly
    def _read(self, timeout):
        ready = self.poll.poll(timeout * 1000)
        if not ready:
            raise Exception("Timeout")
        return os.read(self.fileno, 1)

    # Read a single line from the remote. The ending "\n" will be on the line.
    # Note that "\r" characters are blindly removed.
    def readline(self, timeout = 1):
        line = ""
        while line == "" or line[-1] != "\n":
            c = self._read(timeout)
            if c != "\b":
                line += c
        line = line.replace("\r", "")
        print "<<< \"%s\"" % escapeString(line)
        return line

    # Send a string of RAW data and expect each character to echo back
    def writeEcho(self,str):
        for c in str:
            self.write(c)
            r = self._read(1)
            assert c == r, "Echo %s != %s" % (c, r)

    # Send a line of data and expect it to be echoed back
    def writeEchol(self, str):
        self.write(str + "\r")
        self.matchline(str)

    # Wait for an exact string to be received from the remote
    def matchwait(self, str, timeout = 1):
        complete = []
        current = ""
        while not str in current:
            current+=self._read(timeout)
            if len(current) >= 256:
                complete.append(current[0:128])
                current = current[128:]
        complete.append(current)
        current = "".join(complete)
        for line in current.split("\n"):
            print "<<< \"%s\"" % escapeString(line)
        return current

    # Delay until input is idle for a timeout
    def delay(self, timeout):
        current = []
        try:
            while True:
                current.append(self.readline(timeout))
        except:
            pass
        current = "".join(current)
        return current

    # Exactly match input characters from the remote
    def match(self, correct, timeout = 1):
        input = ""
        while len(input) < len(correct):
            c = self._read(timeout)
            if c != "\b":
                input += c
            assert correct.startswith(input), "\"%s\" != \"%s\"" % (escapeString(input), escapeString(correct))
        print "<<< \"%s\"" % escapeString(input)
        return input

    # Exactly match a line from the remote
    def matchline(self, correct, timeout = 1):
        correct += "\n"
        line = self.readline(timeout)
        assert line == correct, "\"%s\" != \"%s\"" % (escapeString(line), escapeString(correct))
        return line

    # Pattern match a line from the remote
    def patternline(self, pattern, timeout = 1):
        line = self.readline(timeout)
        assert re.match(pattern, line), "\"%s\" != \"%s\"" % (escapeString(pattern), escapeString(line))
        return line

