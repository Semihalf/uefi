
#
# Instruct python to make all symbols global when loading asim (required
# so that simulator external symbols referenced from device models will
# resolve correctly).
#
import sys
import os
import time
import signal

signal.alarm(60 * 60)

BDK_ROOT = os.environ["BDK_ROOT"]
ASIM = os.environ["ASIM"]

try:
    import dl
    sys.setdlopenflags(dl.RTLD_NOW|dl.RTLD_GLOBAL)
except:
    sys.setdlopenflags(0x00002|0x00100)
sys.path.append(ASIM + "/shim/python")
os.environ["ASIM_LIBRARY_PATH"] = ASIM + "/lib"

pipe_r, pipe_w = os.pipe()
UART0PORT = str(pipe_w)
UART1PORT = "1"
os.environ["UART0PORT"] = UART0PORT
os.environ["UART1PORT"] = UART1PORT
os.environ["BIN_IMAGE"] = BDK_ROOT + "/target-bin/normal-generic.bin"
os.environ["SYMBOL_IMAGE"] = BDK_ROOT + "/apps/diagnostics/app"
if not "ASIM_CHIP" in os.environ:
    os.environ["ASIM_CHIP"] = "CN88XX:2.0"

#
# Load the simulator
#
import asim

#
# Create a shim object, send all log output to stdout.
#
sim = asim.Simulator(None)
assert sim

def send(str):
    assert sim.command("control n0.uaa0 input \"%s\\n\"" % str)

def wait_for(wait_str):
    buffer = ""
    while True:
        data = os.read(pipe_r, 1)
        sys.stdout.write(data)
        sys.stdout.flush()
        buffer += data
        buffer = buffer[-200:]
        if buffer.endswith(wait_str):
            break;


#
# Load the common config
#
assert sim.command("@%s/%s.asim" % (BDK_ROOT, os.environ["ASIM_CHIP"].split(":")[0]))
assert sim.command("start 0")

wait_for("Cavium THUNDERX")
wait_for("PASS: CRC32 verification")
wait_for("=========================")
wait_for("Cavium THUNDERX Boot Stub")
wait_for("=========================")
wait_for("Version:")
wait_for("Node:  0")
wait_for("Chip:  0xa")
wait_for("L2:    16384 KB")
wait_for("RCLK:  2500 Mhz")
wait_for("SCLK:  800 Mhz")
wait_for("Boot:  SPI24(5)")
wait_for("VRM:   Enabled")
wait_for("Trust: Disabled")
wait_for("============")
wait_for("Boot Options")
wait_for("============")
wait_for("S) Enter Setup")
wait_for("E) Enter Diagnostics, skipping Setup")
wait_for("F) Select Image from Flash")
wait_for("X) Upload File using Xmodem")
wait_for("Choice:")

send("e")
wait_for("Loading image file '/fatfs/diagnostics.bin'")
wait_for("    Verifying image")
wait_for("    Jumping to image at")
wait_for("---")
wait_for("Cavium THUNDERX")
wait_for("PASS: CRC32 verification")
wait_for("Lua 5.2.0  Copyright (C) 1994-2011 Lua.org, PUC-Rio")

wait_for("THUNDERX Diagnostic")
wait_for("Copyright (C) 2010-2015 Cavium Inc.")
wait_for("Version")

wait_for("=================================")
wait_for("Main Menu")
wait_for("=================================")
wait_for("(INS)Menu choice []:")

send("config multinode 1 quit")
wait_for("=================================")
wait_for("Main Menu")
wait_for("=================================")
wait_for("(INS)Menu choice []:")

send("tg")
wait_for("BDK Traffic Generator")
wait_for("Type \"help\" for a list of commands")
wait_for("(INS)Command>")
time.sleep(2)
node = ""
if "CN88XX" in os.environ["ASIM_CHIP"]:
    node = "N0."
send("default %sFAKE0-%sFAKE3" % (node, node))
wait_for("(INS)Command>")
send("count 100")
wait_for("(INS)Command>")
send("start")
wait_for("(INS)Command>")
time.sleep(2)
send("tx_packets_total")
wait_for("Port %sFAKE0: tx_packets_total = 100" % node)
wait_for("Port %sFAKE1: tx_packets_total = 100" % node)
wait_for("Port %sFAKE2: tx_packets_total = 100" % node)
wait_for("Port %sFAKE3: tx_packets_total = 100" % node)
wait_for("(INS)Command>")
send("tx_octets_total")
wait_for("Port %sFAKE0: tx_octets_total = 6000" % node)
wait_for("Port %sFAKE1: tx_octets_total = 6000" % node)
wait_for("Port %sFAKE2: tx_octets_total = 6000" % node)
wait_for("Port %sFAKE3: tx_octets_total = 6000" % node)
wait_for("(INS)Command>")
send("rx_packets_total")
wait_for("Port %sFAKE0: rx_packets_total = 100" % node)
wait_for("Port %sFAKE1: rx_packets_total = 100" % node)
wait_for("Port %sFAKE2: rx_packets_total = 100" % node)
wait_for("Port %sFAKE3: rx_packets_total = 100" % node)
wait_for("(INS)Command>")
send("rx_octets_total")
wait_for("Port %sFAKE0: rx_octets_total = 6000" % node)
wait_for("Port %sFAKE1: rx_octets_total = 6000" % node)
wait_for("Port %sFAKE2: rx_octets_total = 6000" % node)
wait_for("Port %sFAKE3: rx_octets_total = 6000" % node)
wait_for("(INS)Command>")
send("rx_validation_errors")
wait_for("Port %sFAKE0: rx_validation_errors = 0" % node)
wait_for("Port %sFAKE1: rx_validation_errors = 0" % node)
wait_for("Port %sFAKE2: rx_validation_errors = 0" % node)
wait_for("Port %sFAKE3: rx_validation_errors = 0" % node)
wait_for("(INS)Command>")
send("quit")

wait_for("=================================")
wait_for("Main Menu")
wait_for("=================================")
wait_for("(INS)Menu choice []:")

assert sim.command("stop")
assert sim.command("statistics")

print "***********"
print "Test Passed"
print "***********"

