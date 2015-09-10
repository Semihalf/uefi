
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
os.environ["BIN_IMAGE"] = BDK_ROOT + "/target-bin/bdk.bin"
os.environ["SYMBOL_IMAGE"] = BDK_ROOT + "/bdk-boot/diagnostics"
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
wait_for("BDK version:")
wait_for("===============")
wait_for("BDK Stage1 Boot")
wait_for("===============")
wait_for("Chip:  0xa")
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
wait_for(" 6) Soft reset chip")
wait_for("(INS)Menu choice:")

send("1")
wait_for("(INS)Baudrate:")
send("115200")
wait_for("(INS)Use hardware flow control [y/n]:")
send("y")
wait_for("Changing baudrate to 115200")
wait_for("Baudrate is now 115200")

wait_for("Boot Menu")
wait_for("=========")
wait_for("(INS)Menu choice:")

send("2")
wait_for("Looking for images in MMC0:")
wait_for("No images found")

wait_for("Boot Menu")
wait_for("=========")
wait_for("(INS)Menu choice:")

send("3")
wait_for("Looking for images in SPI0:")
wait_for("  1) /fatfs/SPI0:/diagnostics.bin: diagnostics.bin, version")
wait_for("One image found, automatically loading")
wait_for("    Loading image /fatfs/SPI0:/diagnostics.bin")
wait_for("    Verifying image")
wait_for("    Jumping to image at")
wait_for("---")
wait_for("Cavium THUNDERX")
wait_for("PASS: CRC32 verification")
wait_for("Lua 5.2.0  Copyright (C) 1994-2011 Lua.org, PUC-Rio")

wait_for("THUNDERX Bringup and Diagnostic Kit")
wait_for("Copyright (C) 2010-2015 Cavium Inc.")
wait_for("Version")

wait_for("Configuring for the EBB")

wait_for("=================================")
wait_for("Main Menu")
wait_for("=================================")
wait_for("(INS)Menu choice []:")

assert sim.command("stop")
assert sim.command("statistics")

print "***********"
print "Test Passed"
print "***********"

