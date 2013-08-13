import os
import sys
import pexpect

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
os.environ["OCTEON_REMOTE_PROTOCOL"] = "macraigor:192.168.111.4,1000,2"
os.environ["OCTEON_REMOTE_CONSOLE"] = "/dev/ttyS8"

BDK_BOOT_IMAGE = os.environ["BDK_ROOT"] + "/target-bin/bdk-minimal.bin"

# Test CSR operations
do_command("bdk-remote csr CIU_FUSE", [
    "CIU_FUSE\[0x0001070000000728\] = 0x000000000000000f",
    "\[63: 4\] RESERVED_4_63        =          0 \(0x0\)",
    "\[ 3: 0\] FUSE                 =         15 \(0xf\)"
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
    "\[63: 4\] RESERVED_4_63        =          0 \(0x0\)",
    "\[ 3: 0\] FUSE                 =          3 \(0x3\)"
    ])

# Boot the BDK
do_command("bdk-remote reset", [])
do_command("bdk-remote boot %s" % BDK_BOOT_IMAGE, [], timeout = 120)

# Test the core command
do_command("bdk-remote core 0", [
    "zero           = 0x0000000000000000",
    "Ebase          = 0xffffffff80000000"])
do_command("bdk-remote reg 0 zero", [
    "Core 0, register zero: hex 0x0000000000000000 decimal 0"])
do_command("bdk-remote reg 0 ebase", [
    "Core 0, register Ebase: hex 0xffffffff80000000 decimal -2147483648"])
do_command("bdk-remote reg 0 kscratch3 0x0123456789abcdef", [])
do_command("bdk-remote reg 0 kscratch3", [
    "Core 0, register Kscratch3: hex 0x0123456789abcdef decimal 81985529216486895"])

# Test flash
if True:
    do_command("bdk-remote flash info", [
        "region = {",
        "block_size = 65536 \(0x10000\)",
        "num_blocks = 127 \(0x7f\)",
        "block_size = 8192 \(0x2000\)",
        "num_blocks = 8 \(0x8\)",
        "regions = 2 \(0x2\)",
        "size = 8388608 \(0x800000\)"
        ])
    do_command("bdk-remote flash write mpdemon.py 0x400000", [
        "100%"
        ], timeout = 10*60)
    do_command("bdk-remote flash read tmp 0x400000 %d" % os.stat("mpdemon.py").st_size, [
        "100%"
        ], timeout = 5*60)
    do_command("diff -s tmp mpdemon.py", [
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
do_command("bdk-remote mem load mpdemon.py 0x8", [])
do_command("bdk-remote mem save tmp 0x8 %d" % os.stat("mpdemon.py").st_size, [])
do_command("diff -s tmp mpdemon.py", [
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
do_command("bdk-remote boot %s" % BDK_BOOT_IMAGE, [], timeout=120)
do_command("bdk-lua -l octeon -e 'print(octeon.c.bdk_clock_get_rate(0,1))'", [
    "600000000"])

# Test RPC over serial using full image
#do_command("bdk-remote boot " + os.environ["BDK_ROOT"] + "/target-bin/bdk-full.bin", [], timeout=120)
#do_command("bdk-lua -l octeon -e 'print(octeon.c.bdk_clock_get_rate(0,1))'", ["800000000"])
