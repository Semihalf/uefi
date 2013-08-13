import os
import sys
import pexpect
import time
import socket

def do_command(command, expected, timeout=-1):
    print("**** Command: \"%s\"" % command)
    c = pexpect.spawn(command)
    c.logfile = sys.stdout
    for e in expected:
        c.expect(e, timeout=timeout)
    c.expect(pexpect.EOF, timeout=timeout)
    print("**** Command complete")

# Make sure the environment is setup correctly
assert os.environ["BDK_ROOT"], "BDK_ROOT not defined"
os.environ["OCTEON_REMOTE_PROTOCOL"] = "pci"
HOST_NAME = socket.gethostname()
if HOST_NAME == "octeon":
    os.environ["OCTEON_REMOTE_CONSOLE"] = "/dev/ttyS1"
else:
    os.environ["OCTEON_REMOTE_CONSOLE"] = "/dev/ttyS0"

BDK_BOOT_IMAGE = os.environ["BDK_ROOT"] + "/target-bin/bdk-boot.bin"
BDK_BOOT_IMAGE_SIZE = os.stat(BDK_BOOT_IMAGE).st_size

# Make sure the Octeon is there and responds correctly
do_command("lspci", [
    "MIPS: Cavium Networks Octeon II CN63XX Network Processor \(rev 0[0-9a-f]\)"
    ])

# Test CSR operations
do_command("bdk-remote csr CIU_FUSE", [
    "CIU_FUSE\[0x0001070000000728\] = 0x000000000000003f",
    "\[63: 6\] RESERVED_6_63        =          0 \(0x0\)",
    "\[ 5: 0\] FUSE                 =         63 \(0x3f\)"
    ])

do_command("bdk-remote csr SLI_SCRATCH_1 0x1234", [])
do_command("bdk-remote csr SLI_SCRATCH_1", [
    "SLI_SCRATCH_1\[0x00011f00000103c0\] = 0x0000000000001234",
    "\[63: 0\] DATA                 =       4660 \(0x1234\)"
    ])
do_command("bdk-remote csr SLI_SCRATCH_1 0", [])
do_command("bdk-remote csr SLI_SCRATCH_1", [
    "SLI_SCRATCH_1\[0x00011f00000103c0\] = 0x0000000000000000",
    "\[63: 0\] DATA                 =          0 \(0x0\)"
    ])

do_command("bdk-remote csr CIU_FUSE 0x3 decode", [
    "CIU_FUSE\[0x0001070000000728\] = 0x0000000000000003",
    "\[63: 6\] RESERVED_6_63        =          0 \(0x0\)",
    "\[ 5: 0\] FUSE                 =          3 \(0x3\)"
    ])

# Boot the BDK
do_command("bdk-remote reset", [])
do_command("bdk-remote boot %s" % BDK_BOOT_IMAGE, [])

# Test the core command
do_command("bdk-remote core 0", [
    "zero           = 0x0000000000000000",
    "Ebase          = 0x0000000080000000",
    "128: Virtual=", "Page0=0x000000000,C=0,D=0,V=0,G=0,RI=0,XI=0 Page1=0x000000000,C=0,D=0,V=0,G=0,RI=0,XI=0 ASID=  0 Size=4KB"], timeout=60)
do_command("bdk-remote reg 0 zero", [
    "Core 0, register zero: hex 0x0000000000000000 decimal 0"])
do_command("bdk-remote reg 0 ebase", [
    "Core 0, register Ebase: hex 0x0000000080000000 decimal 2147483648"])
do_command("bdk-remote reg 0 kscratch3 0x0123456789abcdef", [])
do_command("bdk-remote reg 0 kscratch3", [
    "Core 0, register Kscratch3: hex 0x0123456789abcdef decimal 81985529216486895"])

# Test flash
if True:
    do_command("bdk-remote flash info", [
        "region = {",
        "block_size = 131072 \(0x20000\)",
        "num_blocks = 32 \(0x20\)",
        "regions = 1 \(0x1\)",
        "size = 4194304 \(0x400000\)"
        ], timeout=60)
    do_command("bdk-remote flash write %s 0x200000" % BDK_BOOT_IMAGE, [
        "100%"
        ], timeout = 360)
    do_command("bdk-remote flash read tmp 0x200000 %d" % BDK_BOOT_IMAGE_SIZE, [
        "100%"
        ], timeout = 300)
    do_command("diff -s tmp %s" % BDK_BOOT_IMAGE, [
        "are identical"
        ])
    do_command("rm -f tmp", [])

# Test memory ops
do_command("bdk-remote mem 8 0x8 0x0123456789abcdef", [])
do_command("bdk-remote mem 0x8", [
    "Address 0x0000000000000008 = 0x0123456789abcdef"
    ])
do_command("bdk-remote mem 4 0x8", [
    "Address 0x0000000000000008 = 0x01234567"
    ])
do_command("bdk-remote mem 2 0xa", [
    "Address 0x000000000000000a = 0x4567"
    ])
do_command("bdk-remote mem 1 0xb", [
    "Address 0x000000000000000b = 0x67"
    ])
do_command("bdk-remote mem load nic10e.py 0x8", [])
do_command("bdk-remote mem save tmp 0x8 %d" % os.stat("nic10e.py").st_size, [])
do_command("diff -s tmp nic10e.py", [
    "are identical"
    ])
do_command("rm -f tmp", [])

# Test the profile command
# FIXME
#do_command("bdk-remote profile 1", [])
#do_command("bdk-remote profile", [])

do_command("bdk-remote help", [
    "Parameter descriptions:",
    "zero"])

# Test RPC over serial
do_command("bdk-remote boot %s" % BDK_BOOT_IMAGE, [])
time.sleep(1);
do_command("bdk-lua -l octeon -e 'print(octeon.c.bdk_clock_get_rate(0,1))'", [
    "800000000"])

# Test RPC over serial using minimal image
do_command("bdk-remote boot " + os.environ["BDK_ROOT"] + "/target-bin/bdk-minimal.bin", [])
time.sleep(1);
do_command("bdk-lua -l octeon -e 'print(octeon.c.bdk_clock_get_rate(0,1))'", [
    "800000000"])
