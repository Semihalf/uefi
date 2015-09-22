
#
# Instruct python to make all symbols global when loading asim (required
# so that simulator external symbols referenced from device models will
# resolve correctly).
#
import sys
import os
import signal

signal.alarm(10 * 60)

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
os.environ["BIN_IMAGE"] = BDK_ROOT + "/target-bin/normal-ebb8800.bin"
os.environ["SYMBOL_IMAGE"] = BDK_ROOT + "/normal-boot/ebb8800/diagnostics"
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
wait_for("===========================")
wait_for("Cavium THUNDERX Chainloader")
wait_for("===========================")
wait_for("Version:")
wait_for("Boot Attempt: 1")
wait_for("Node:  0")
wait_for("Chip:  0xa1 Pass")
wait_for("L2:    16384 KB")
wait_for("RCLK:  2500 Mhz")
wait_for("SCLK:  800 Mhz")
wait_for("Boot:  SPI24(5)")
wait_for("VRM:   Enabled")
wait_for("Trust: Disabled")
wait_for("Loading image file '/fatfs/stage1.bin'")
wait_for("Verifying image")
wait_for("Jumping to image at")
wait_for("---")
wait_for("Cavium THUNDERX")
wait_for("PASS: CRC32 verification")
wait_for("Press X to boot in safe mode...")
wait_for("=========================")
wait_for("Cavium THUNDERX Boot Stub")
wait_for("=========================")
wait_for("BDK version:")
wait_for("N0: QLM Config: Configuring QLMs for a sample setup")
#wait_for("N1: QLM Config: Configuring QLMs for a sample setup")
wait_for("Press 'D' within 3 seconds to boot diagnostics")
wait_for("Loading image at /dev/n0.mpi0/cs-l,2wire,idle-h,msb,24bit,12:0x400000")
wait_for("ERROR: Image header is corrupt")
wait_for("ERROR: Unable to load image")
wait_for("Trying diagnostics")
wait_for("Loading image file '/fatfs/stage2.bin'")
wait_for("Verifying image")
wait_for("Jumping to image at")
wait_for("---")
wait_for("Cavium THUNDERX")
wait_for("PASS: CRC32 verification")
wait_for("Lua 5.2.0  Copyright (C) 1994-2011 Lua.org, PUC-Rio")

wait_for("THUNDERX Diagnostics")
wait_for("Copyright (C) 2010-2015 Cavium Inc.")
wait_for("Version")

wait_for("Configuring for the EBB8800")

wait_for("=================================")
wait_for("Main Menu")
wait_for("=================================")
wait_for("(INS)Menu choice []:")

assert sim.command("stop")
assert sim.command("statistics")

print "***********"
print "Test Passed"
print "***********"

