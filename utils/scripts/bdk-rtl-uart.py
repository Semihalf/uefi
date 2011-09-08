#!/usr/bin/python

import sys

for line in open("logfile"):
    if "UART0: offset: 0x0001180000000840 val: " in line:
        val = long(line.split()[-1], 0)
        sys.stdout.write(chr(val))
