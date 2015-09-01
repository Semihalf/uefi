
#
# Instruct python to make all symbols global when loading asim (required
# so that simulator external symbols referenced from device models will
# resolve correctly).
#
import sys
import os
import time
import signal

signal.alarm(30 * 60)

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
assert sim.command("@%s/bdk.asim" % BDK_ROOT)
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
wait_for("Configuring QLMs for a sample setup")

wait_for("=================================")
wait_for("Main Menu")
wait_for("=================================")
wait_for("(INS)Menu choice []:")

send("sata")
wait_for("=================================")
wait_for("SATA Menu")
wait_for("=================================")
wait_for(" 1) Select SATA port (Currently 0)")
wait_for(" 2) Perform an identify disk")
wait_for(" 3) Issue BIST FIS - Far-end Retimed Loopback")
wait_for(" 4) Issue BIST FIS - Far-end Analog Loopback")
wait_for(" 5) Issue BIST FIS - Far-end Transmit Only")
wait_for(" 6) Enter Local-end Retimed Loopback")
wait_for(" 7) Enter Local-end Transmit Only")
wait_for(" 8) Reset the controller")
wait_for(" 9) Hex display")
wait_for("10) Write pattern 0x00")
wait_for("11) Read  pattern 0x00")
wait_for("12) Write pattern 0xff")
wait_for("13) Read  pattern 0xff")
wait_for("14) Write pattern 0x55")
wait_for("15) Read  pattern 0x55")
wait_for("16) Write pattern 0xaa")
wait_for("17) Read  pattern 0xaa")
wait_for("18) Run automated pattern test")
wait_for("19) Main menu")
wait_for("(INS)Menu choice []:")
serial = 1
sata_port = [0,1]
if "CN88XX" in os.environ["ASIM_CHIP"]:
    sata_port = [8,15]
for sata in sata_port:
    sata_file = "test_disk-%d.tmp" % os.getpid()
    assert(os.system("dd if=/dev/zero of=%s bs=1M count=1" % sata_file) == 0)
    assert sim.command("control n0.ahci%d connect ide 0 %s" % (sata, sata_file))
    send("port %d" % sata)
    wait_for("=================================")
    wait_for("SATA Menu")
    wait_for("=================================")
    wait_for(" 1) Select SATA port (Currently %d)" % sata)
    wait_for("(INS)Menu choice []:")
    send("id")
    wait_for("SATA%d: Model=\"HARDDISK\", Firmware=\"ASIM\", Serial=\"QM0000%d\", Sectors=2016, Link=Gen3" % (sata, serial))
    serial += 1
    wait_for("=================================")
    wait_for("SATA Menu")
    wait_for("=================================")
    wait_for("(INS)Menu choice []:")
    send("auto")
    wait_for("(INS)Repeat count (-1 for infinite) [1]:")
    send("1")
    for sectors in range(1,129):
        wait_for("Testing %d sector accesses" % sectors)
    wait_for("=================================")
    wait_for("SATA Menu")
    wait_for("=================================")
    wait_for("(INS)Menu choice []:")
    assert sim.command("control n0.ahci%d disconnect 0" % sata)
    assert(os.system("rm %s" % sata_file) == 0)

assert sim.command("stop")
assert sim.command("statistics")

print "***********"
print "Test Passed"
print "***********"

