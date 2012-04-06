#!/usr/bin/python

import re
import os

#
# Create a serial connection. The connect_string is of the format
# "device,baud". The "device" is a unix device file (/dev/ttyS0). The
# ",baud" is an optional baud rate that defaults to 115200.
#
def SerialConnection(connection, connect_string):
    assert connect_string.startswith("/dev/"), "Invalid serial port"
    match = re.match("^([^,]+)(,[0-9]+)?$", connect_string)
    assert match, "Invalid serial connect string"
    connection.device = match.group(1)
    baud_string = match.group(2)
    connection.baudrate = 115200
    if baud_string:
        connection.baudrate = int(baud_string[1:])
        assert connection.baudrate >= 300
    # Set the baud rate of the serial port
    if os.system("stty --file=" + connection.device + " " + str(connection.baudrate)):
        raise Exception("stty failed")
    # Open the serial port
    connection.fileno = os.open(connection.device, os.O_RDWR | os.O_SYNC | os.O_NDELAY)

