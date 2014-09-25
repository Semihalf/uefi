
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
os.environ["BIN_IMAGE"] = BDK_ROOT + "/target-bin/bdk.bin"
os.environ["SYMBOL_IMAGE"] = BDK_ROOT + "/bdk-boot/diagnostics"

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
assert sim.command("@%s/bdk.asim" % BDK_ROOT)
assert sim.command("start 0")

wait_for("Bringup and Diagnostic Kit (BDK)")
wait_for("PASS: CRC32 verification")
wait_for("Transferring to thread scheduler")
wait_for("Performing common initialization")
wait_for("N0: Performing node initialization")
wait_for("Switching to main")
wait_for("BDK version:")
wait_for("===============")
wait_for("BDK Stage1 Boot")
wait_for("===============")
wait_for("Node:  0")
wait_for("Chip:  0xa1 Pass 1.0")
wait_for("RCLK:  2500 Mhz")
wait_for("SCLK:  800 Mhz")
wait_for("Boot:  SPI24(5)")
wait_for("VRM:   Enabled")
wait_for("Trust: Disabled")
wait_for("Boot Menu")
wait_for("=========")
wait_for(" 1) Change baud rate and flow control")
wait_for(" 2) Load image from MMC, eMMC, or SD")
wait_for(" 3) Load image from SPI")
wait_for(" 4) Write image to MMC, eMMC, or SD using Xmodem")
wait_for(" 5) Write image to SPI EEPROM or NOR using Xmodem")
wait_for(" 6) DRAM options")
wait_for(" 7) Soft reset chip")
wait_for("(INS)Menu choice:")

send("3")
wait_for("Looking for images in /dev/mpi/cs0-l,2wire,idle-h,msb,24bit,12")
wait_for("  1) 0x080000: stage2.bin, version")
wait_for("One image found, automatically loading")
wait_for("    Loading image at 0x80000")
wait_for("    Verifying image")
wait_for("    Jumping to image at")
wait_for("---")
wait_for("Bringup and Diagnostic Kit (BDK)")
wait_for("PASS: CRC32 verification")
wait_for("Transferring to thread scheduler")
wait_for("Performing common initialization")
wait_for("N0: Performing node initialization")
wait_for("Switching to main")
wait_for("Lua 5.2.0  Copyright (C) 1994-2011 Lua.org, PUC-Rio")

wait_for("THUNDERX Bringup and Diagnostic Kit")
wait_for("Copyright (C) 2010-2014 Cavium Networks")
wait_for("Version")

wait_for("Configuring for the EBB8800")
wait_for("Configuring QLMs for a sample setup")

wait_for("=================================")
wait_for("Main Menu")
wait_for("=================================")
wait_for("(INS)Menu choice []:")

send("tg")
wait_for("BDK Traffic Generator")
wait_for("Type \"help\" for a list of commands")
wait_for("(INS)Command>")
time.sleep(2)
send("default fake0-fake3")
wait_for("(INS)Command>")
send("count 100")
wait_for("(INS)Command>")
send("start")
wait_for("(INS)Command>")
time.sleep(2)
send("tx_packets_total")
wait_for("Port FAKE0: tx_packets_total = 100")
wait_for("Port FAKE1: tx_packets_total = 100")
wait_for("Port FAKE2: tx_packets_total = 100")
wait_for("Port FAKE3: tx_packets_total = 100")
wait_for("(INS)Command>")
send("tx_octets_total")
wait_for("Port FAKE0: tx_octets_total = 6000")
wait_for("Port FAKE1: tx_octets_total = 6000")
wait_for("Port FAKE2: tx_octets_total = 6000")
wait_for("Port FAKE3: tx_octets_total = 6000")
wait_for("(INS)Command>")
send("rx_packets_total")
wait_for("Port FAKE0: rx_packets_total = 100")
wait_for("Port FAKE1: rx_packets_total = 100")
wait_for("Port FAKE2: rx_packets_total = 100")
wait_for("Port FAKE3: rx_packets_total = 100")
wait_for("(INS)Command>")
send("rx_octets_total")
wait_for("Port FAKE0: rx_octets_total = 6000")
wait_for("Port FAKE1: rx_octets_total = 6000")
wait_for("Port FAKE2: rx_octets_total = 6000")
wait_for("Port FAKE3: rx_octets_total = 6000")
wait_for("(INS)Command>")
send("rx_validation_errors")
wait_for("Port FAKE0: rx_validation_errors = 0")
wait_for("Port FAKE1: rx_validation_errors = 0")
wait_for("Port FAKE2: rx_validation_errors = 0")
wait_for("Port FAKE3: rx_validation_errors = 0")
wait_for("(INS)Command>")
send("default fake1")
wait_for("(INS)Command>")
send("scan_sizes")
for size in xrange(60,9213):
    wait_for("Size %d" % size)
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

