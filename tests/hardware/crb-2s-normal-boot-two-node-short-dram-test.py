from connect_crb_2s import Connection

def boot_test(cnx):
    cnx.powerCycle()
    cnx.waitfor("Cavium THUNDERX", timeout=20)
    cnx.match("PASS: CRC32 verification")
    cnx.match("BDK version: 2015.01-r")
    cnx.waitfor("=========================")
    cnx.match("Cavium THUNDERX Boot Stub")
    cnx.match("=========================")
    cnx.match("Node:  0 (Fixed)")
    cnx.match("Chip:  0xa1 Pass 1.0")
    cnx.match("L2:    16384 KB")
    cnx.match("RCLK:  1900 Mhz")
    cnx.match("SCLK:  700 Mhz")
    cnx.match("Boot:  SPI24(5)")
    cnx.match("VRM:   Disabled")
    cnx.match("Trust: Disabled")
    cnx.match("Node 0: DRAM: 32768 MB, 1067 MHz")
    cnx.match("N0.CCPI Applying lane reversal")
    cnx.match("N0.CCPI Lanes([] is good):[0][1][2][3][4][5][6][7][8][9][10][11][12][13][14][15][16][17][18][19][20][21][22][23]")
    cnx.match("N1.CCPI Lanes([] is good):[0][1][2][3][4][5][6][7][8][9][10][11][12][13][14][15][16][17][18][19][20][21][22][23]")
    cnx.match("Node:  1 (Fixed)")
    cnx.match("Chip:  0xa1 Pass 1.0")
    cnx.match("L2:    16384 KB")
    cnx.match("RCLK:  1900 Mhz")
    cnx.match("SCLK:  700 Mhz")
    cnx.match("Boot:  SPI24(5)")
    cnx.match("VRM:   Disabled")
    cnx.match("Trust: Disabled")
    cnx.match("Node 1: DRAM: 32768 MB, 1067 MHz", timeout=20)
    cnx.match("N0.PCIe0: Link timeout, probably the slot is empty")
    cnx.match("N0.PCIe2: Link timeout, probably the slot is empty")
    cnx.match("N0.PCIe4: Link timeout, probably the slot is empty")
    cnx.match("Press 'D' within 3 seconds to boot diagnostics")
    cnx.write("D")
    cnx.match("Loading image at 0x80000")
    cnx.match("Verifying image")
    cnx.match("Putting all cores except this one in reset")
    cnx.match("Jumping to image at 0x3a180")
    cnx.match("---")
    cnx.match("Cavium THUNDERX")
    cnx.match("PASS: CRC32 verification")
    cnx.match("Lua 5.2.0  Copyright (C) 1994-2011 Lua.org, PUC-Rio")
    cnx.match("THUNDERX Diagnostics")
    cnx.match("Copyright (C) 2010-2014 Cavium Inc.")
    cnx.match("Version 2015.01-r")
    cnx.waitfor("Configuring for the CN88XX-CRB-2S")
    cnx.match("=================================")
    cnx.match("Main Menu")
    cnx.match("=================================")
    cnx.match("1) SERDES configuration")
    cnx.match("2) Software configuration")
    cnx.match("3) File options")
    cnx.match("4) DDR options")
    cnx.match("5) PCIe options")
    cnx.match("6) TWSI options")
    cnx.match("7) SMI/MDIO options")
    cnx.match("8) SPI/MPI options")
    cnx.match("9) eMMC/SD options")
    cnx.match("10) SATA options")
    cnx.match("11) GPIO options")
    cnx.match("12) USB options")
    cnx.match("13) Interactive Lua prompt")
    cnx.match("14) Traffic Generator")
    cnx.match("15) Burn power")
    cnx.match("16) Set power throttle level")
    cnx.match("17) Reboot")
    cnx.match("18) Run board test")
    cnx.match("(INS)Menu choice []:")
    cnx.sendEcho("keys")
    cnx.waitfor("=================================")
    cnx.match("Main Menu")
    cnx.match("=================================")
    cnx.match("qlm) SERDES configuration")
    cnx.match("config) Software configuration")
    cnx.match("file) File options")
    cnx.match("ddr) DDR options")
    cnx.match("pcie) PCIe options")
    cnx.match("twsi) TWSI options")
    cnx.match("smi) SMI/MDIO options")
    cnx.match("mpi) SPI/MPI options")
    cnx.match("emmc) eMMC/SD options")
    cnx.match("sata) SATA options")
    cnx.match("gpio) GPIO options")
    cnx.match("usb) USB options")
    cnx.match("ilua) Interactive Lua prompt")
    cnx.match("tg) Traffic Generator")
    cnx.match("burn) Burn power")
    cnx.match("throt) Set power throttle level")
    cnx.match("rbt) Reboot")
    cnx.match("brdtest) Run board test")
    cnx.match("(INS)Menu choice []:")

def dram_test(cnx):
    cnx.sendEcho("ddr")
    cnx.match("=================================")
    cnx.match("DRAM Menu")
    cnx.match("=================================")
    cnx.match("node) Select active node (Currently 0)")
    cnx.match("verbose) Toggle verbose output (Currently OFF)")
    cnx.match("setenv) Set environment variable")
    cnx.match("getenv) Get environment variable")
    cnx.match("showenv) Show environment variables")
    cnx.match("ebb8800) Initialize DRAM using config \"ebb8800\"")
    cnx.match("ebb8804) Initialize DRAM using config \"ebb8804\"")
    cnx.match("cn88xx-crb-1s) Initialize DRAM using config \"cn88xx-crb-1s\"")
    cnx.match("cn88xx-crb-2s) Initialize DRAM using config \"cn88xx-crb-2s\"")
    cnx.match("test) Memory Testing Menu")
    cnx.match("quit) Main menu")
    cnx.match("(INS)Menu choice []:")
    cnx.sendEcho("test")
    cnx.match("=================================")
    cnx.match("DRAM Test Menu")
    cnx.match("=================================")
    cnx.match("cores) Bringup Cores for multi-core testing")
    cnx.match("repeat) Number of time to repeat the test (1)")
    cnx.match("start) Starting address (0x0)")
    cnx.match("length) Length of the range to check (All)")
    cnx.match("64MB) Set test range from 64MB to 128MB")
    cnx.match("all) Run all DRAM tests")
    cnx.match("test0) Data Bus")
    cnx.match("test1) Address Bus")
    cnx.match("test2) Marching Rows")
    cnx.match("test3) Random Data")
    cnx.match("test4) Random XOR (32 Burst)")
    cnx.match("test5) Self Address")
    cnx.match("test6) March C- Solid Bits")
    cnx.match("test7) March C- Checkerboard")
    cnx.match("test8) Walking Ones Left")
    cnx.match("test9) Walking Ones Right")
    cnx.match("test10) Walking Zeros Left")
    cnx.match("test11) Walking Zeros Right")
    cnx.match("test12) Random XOR (224 Burst)")
    cnx.match("quit) Main menu")
    cnx.match("(INS)Menu choice []:")
    cnx.sendEcho("cores")
    cnx.match("=================================")
    cnx.match("DRAM Test Menu")
    cnx.match("=================================")
    cnx.match("cores) Bringup Cores for multi-core testing")
    cnx.match("repeat) Number of time to repeat the test (1)")
    cnx.match("start) Starting address (0x0)")
    cnx.match("length) Length of the range to check (All)")
    cnx.match("64MB) Set test range from 64MB to 128MB")
    cnx.match("all) Run all DRAM tests")
    cnx.match("test0) Data Bus")
    cnx.match("test1) Address Bus")
    cnx.match("test2) Marching Rows")
    cnx.match("test3) Random Data")
    cnx.match("test4) Random XOR (32 Burst)")
    cnx.match("test5) Self Address")
    cnx.match("test6) March C- Solid Bits")
    cnx.match("test7) March C- Checkerboard")
    cnx.match("test8) Walking Ones Left")
    cnx.match("test9) Walking Ones Right")
    cnx.match("test10) Walking Zeros Left")
    cnx.match("test11) Walking Zeros Right")
    cnx.match("test12) Random XOR (224 Burst)")
    cnx.match("quit) Main menu")
    cnx.match("(INS)Menu choice []:")
    cnx.sendEcho("64MB")
    cnx.match("=================================")
    cnx.match("DRAM Test Menu")
    cnx.match("=================================")
    cnx.match("cores) Bringup Cores for multi-core testing")
    cnx.match("repeat) Number of time to repeat the test (1)")
    cnx.match("start) Starting address (0x4000000)")
    cnx.match("length) Length of the range to check (0x4000000)")
    cnx.match("64MB) Set test range from 64MB to 128MB")
    cnx.match("all) Run all DRAM tests")
    cnx.match("test0) Data Bus")
    cnx.match("test1) Address Bus")
    cnx.match("test2) Marching Rows")
    cnx.match("test3) Random Data")
    cnx.match("test4) Random XOR (32 Burst)")
    cnx.match("test5) Self Address")
    cnx.match("test6) March C- Solid Bits")
    cnx.match("test7) March C- Checkerboard")
    cnx.match("test8) Walking Ones Left")
    cnx.match("test9) Walking Ones Right")
    cnx.match("test10) Walking Zeros Left")
    cnx.match("test11) Walking Zeros Right")
    cnx.match("test12) Random XOR (224 Burst)")
    cnx.match("quit) Main menu")
    cnx.match("(INS)Menu choice []:")
    cnx.sendEcho("all")
    cnx.match("Pass 1 of 1")
    cnx.match("Starting Test \"Data Bus\" for [0x00004000000:0x00007ffffff]")
    cnx.waitfor("Node 0, LMC0: ops")
    cnx.waitfor("Node 0, LMC1: ops")
    cnx.waitfor("Node 0, LMC2: ops")
    cnx.waitfor("Node 0, LMC3: ops")
    cnx.waitfor("Node 1, LMC0: ops")
    cnx.waitfor("Node 1, LMC1: ops")
    cnx.waitfor("Node 1, LMC2: ops")
    cnx.waitfor("Node 1, LMC3: ops")
    cnx.waitfor("%")
    cnx.match("Starting Test \"Address Bus\" for [0x00004000000:0x00007ffffff]")
    cnx.waitfor("Node 0, LMC0: ops")
    cnx.waitfor("Node 0, LMC1: ops")
    cnx.waitfor("Node 0, LMC2: ops")
    cnx.waitfor("Node 0, LMC3: ops")
    cnx.waitfor("Node 1, LMC0: ops")
    cnx.waitfor("Node 1, LMC1: ops")
    cnx.waitfor("Node 1, LMC2: ops")
    cnx.waitfor("Node 1, LMC3: ops")
    cnx.waitfor("%")
    cnx.match("Starting Test \"Marching Rows\" for [0x00004000000:0x00007ffffff]")
    cnx.waitfor("Node 0, LMC0: ops")
    cnx.waitfor("Node 0, LMC1: ops")
    cnx.waitfor("Node 0, LMC2: ops")
    cnx.waitfor("Node 0, LMC3: ops")
    cnx.waitfor("Node 1, LMC0: ops")
    cnx.waitfor("Node 1, LMC1: ops")
    cnx.waitfor("Node 1, LMC2: ops")
    cnx.waitfor("Node 1, LMC3: ops")
    cnx.waitfor("%")
    cnx.match("Starting Test \"Random Data\" for [0x00004000000:0x00007ffffff]")
    cnx.waitfor("Node 0, LMC0: ops")
    cnx.waitfor("Node 0, LMC1: ops")
    cnx.waitfor("Node 0, LMC2: ops")
    cnx.waitfor("Node 0, LMC3: ops")
    cnx.waitfor("Node 1, LMC0: ops")
    cnx.waitfor("Node 1, LMC1: ops")
    cnx.waitfor("Node 1, LMC2: ops")
    cnx.waitfor("Node 1, LMC3: ops")
    cnx.waitfor("%")
    cnx.match("Starting Test \"Random XOR (32 Burst)\" for [0x00004000000:0x00007ffffff]")
    cnx.waitfor("Node 0, LMC0: ops")
    cnx.waitfor("Node 0, LMC1: ops")
    cnx.waitfor("Node 0, LMC2: ops")
    cnx.waitfor("Node 0, LMC3: ops")
    cnx.waitfor("Node 1, LMC0: ops")
    cnx.waitfor("Node 1, LMC1: ops")
    cnx.waitfor("Node 1, LMC2: ops")
    cnx.waitfor("Node 1, LMC3: ops")
    cnx.waitfor("%")
    cnx.match("Starting Test \"Self Address\" for [0x00004000000:0x00007ffffff]")
    cnx.waitfor("Node 0, LMC0: ops")
    cnx.waitfor("Node 0, LMC1: ops")
    cnx.waitfor("Node 0, LMC2: ops")
    cnx.waitfor("Node 0, LMC3: ops")
    cnx.waitfor("Node 1, LMC0: ops")
    cnx.waitfor("Node 1, LMC1: ops")
    cnx.waitfor("Node 1, LMC2: ops")
    cnx.waitfor("Node 1, LMC3: ops")
    cnx.waitfor("%")
    cnx.match("Starting Test \"March C- Solid Bits\" for [0x00004000000:0x00007ffffff]")
    cnx.waitfor("Node 0, LMC0: ops")
    cnx.waitfor("Node 0, LMC1: ops")
    cnx.waitfor("Node 0, LMC2: ops")
    cnx.waitfor("Node 0, LMC3: ops")
    cnx.waitfor("Node 1, LMC0: ops")
    cnx.waitfor("Node 1, LMC1: ops")
    cnx.waitfor("Node 1, LMC2: ops")
    cnx.waitfor("Node 1, LMC3: ops")
    cnx.waitfor("%")
    cnx.match("Starting Test \"March C- Checkerboard\" for [0x00004000000:0x00007ffffff]")
    cnx.waitfor("Node 0, LMC0: ops")
    cnx.waitfor("Node 0, LMC1: ops")
    cnx.waitfor("Node 0, LMC2: ops")
    cnx.waitfor("Node 0, LMC3: ops")
    cnx.waitfor("Node 1, LMC0: ops")
    cnx.waitfor("Node 1, LMC1: ops")
    cnx.waitfor("Node 1, LMC2: ops")
    cnx.waitfor("Node 1, LMC3: ops")
    cnx.waitfor("%")
    cnx.match("Starting Test \"Walking Ones Left\" for [0x00004000000:0x00007ffffff]")
    cnx.waitfor("Node 0, LMC0: ops")
    cnx.waitfor("Node 0, LMC1: ops")
    cnx.waitfor("Node 0, LMC2: ops")
    cnx.waitfor("Node 0, LMC3: ops")
    cnx.waitfor("Node 1, LMC0: ops")
    cnx.waitfor("Node 1, LMC1: ops")
    cnx.waitfor("Node 1, LMC2: ops")
    cnx.waitfor("Node 1, LMC3: ops")
    cnx.waitfor("%")
    cnx.match("Starting Test \"Walking Ones Right\" for [0x00004000000:0x00007ffffff]")
    cnx.waitfor("Node 0, LMC0: ops")
    cnx.waitfor("Node 0, LMC1: ops")
    cnx.waitfor("Node 0, LMC2: ops")
    cnx.waitfor("Node 0, LMC3: ops")
    cnx.waitfor("Node 1, LMC0: ops")
    cnx.waitfor("Node 1, LMC1: ops")
    cnx.waitfor("Node 1, LMC2: ops")
    cnx.waitfor("Node 1, LMC3: ops")
    cnx.waitfor("%")
    cnx.match("Starting Test \"Walking Zeros Left\" for [0x00004000000:0x00007ffffff]")
    cnx.waitfor("Node 0, LMC0: ops")
    cnx.waitfor("Node 0, LMC1: ops")
    cnx.waitfor("Node 0, LMC2: ops")
    cnx.waitfor("Node 0, LMC3: ops")
    cnx.waitfor("Node 1, LMC0: ops")
    cnx.waitfor("Node 1, LMC1: ops")
    cnx.waitfor("Node 1, LMC2: ops")
    cnx.waitfor("Node 1, LMC3: ops")
    cnx.waitfor("%")
    cnx.match("Starting Test \"Walking Zeros Right\" for [0x00004000000:0x00007ffffff]")
    cnx.waitfor("Node 0, LMC0: ops")
    cnx.waitfor("Node 0, LMC1: ops")
    cnx.waitfor("Node 0, LMC2: ops")
    cnx.waitfor("Node 0, LMC3: ops")
    cnx.waitfor("Node 1, LMC0: ops")
    cnx.waitfor("Node 1, LMC1: ops")
    cnx.waitfor("Node 1, LMC2: ops")
    cnx.waitfor("Node 1, LMC3: ops")
    cnx.waitfor("%")
    cnx.match("Starting Test \"Random XOR (224 Burst)\" for [0x00004000000:0x00007ffffff]")
    cnx.waitfor("Node 0, LMC0: ops")
    cnx.waitfor("Node 0, LMC1: ops")
    cnx.waitfor("Node 0, LMC2: ops")
    cnx.waitfor("Node 0, LMC3: ops")
    cnx.waitfor("Node 1, LMC0: ops")
    cnx.waitfor("Node 1, LMC1: ops")
    cnx.waitfor("Node 1, LMC2: ops")
    cnx.waitfor("Node 1, LMC3: ops")
    cnx.waitfor("%")
    cnx.match("All tests passed (time 0:0:")
    cnx.waitfor("\\)")
    cnx.match("=================================")
    cnx.match("DRAM Test Menu")
    cnx.match("=================================")
    cnx.match("cores) Bringup Cores for multi-core testing")
    cnx.match("repeat) Number of time to repeat the test (1)")
    cnx.match("start) Starting address (0x4000000)")
    cnx.match("length) Length of the range to check (0x4000000)")
    cnx.match("64MB) Set test range from 64MB to 128MB")
    cnx.match("all) Run all DRAM tests")
    cnx.match("test0) Data Bus")
    cnx.match("test1) Address Bus")
    cnx.match("test2) Marching Rows")
    cnx.match("test3) Random Data")
    cnx.match("test4) Random XOR (32 Burst)")
    cnx.match("test5) Self Address")
    cnx.match("test6) March C- Solid Bits")
    cnx.match("test7) March C- Checkerboard")
    cnx.match("test8) Walking Ones Left")
    cnx.match("test9) Walking Ones Right")
    cnx.match("test10) Walking Zeros Left")
    cnx.match("test11) Walking Zeros Right")
    cnx.match("test12) Random XOR (224 Burst)")
    cnx.match("quit) Main menu")
    cnx.match("(INS)Menu choice []:")
    cnx.sendEcho("quit")
    cnx.match("=================================")
    cnx.match("DRAM Menu")
    cnx.match("=================================")
    cnx.match("node) Select active node (Currently 0)")
    cnx.match("verbose) Toggle verbose output (Currently OFF)")
    cnx.match("setenv) Set environment variable")
    cnx.match("getenv) Get environment variable")
    cnx.match("showenv) Show environment variables")
    cnx.match("ebb8800) Initialize DRAM using config \"ebb8800\"")
    cnx.match("ebb8804) Initialize DRAM using config \"ebb8804\"")
    cnx.match("cn88xx-crb-1s) Initialize DRAM using config \"cn88xx-crb-1s\"")
    cnx.match("cn88xx-crb-2s) Initialize DRAM using config \"cn88xx-crb-2s\"")
    cnx.match("test) Memory Testing Menu")
    cnx.match("quit) Main menu")
    cnx.match("(INS)Menu choice []:")
    cnx.sendEcho("quit")
    cnx.match("=================================")
    cnx.match("Main Menu")
    cnx.match("=================================")
    cnx.match("qlm) SERDES configuration")
    cnx.match("config) Software configuration")
    cnx.match("file) File options")
    cnx.match("ddr) DDR options")
    cnx.match("pcie) PCIe options")
    cnx.match("twsi) TWSI options")
    cnx.match("smi) SMI/MDIO options")
    cnx.match("mpi) SPI/MPI options")
    cnx.match("emmc) eMMC/SD options")
    cnx.match("sata) SATA options")
    cnx.match("gpio) GPIO options")
    cnx.match("usb) USB options")
    cnx.match("ilua) Interactive Lua prompt")
    cnx.match("tg) Traffic Generator")
    cnx.match("burn) Burn power")
    cnx.match("throt) Set power throttle level")
    cnx.match("rbt) Reboot")
    cnx.match("brdtest) Run board test")
    cnx.match("(INS)Menu choice []:")

def main():
    count = 0
    while True:
        count += 1
        print "Loop %d" % count
        cnx = Connection(console="/dev/ttyUSB2", mcu="/dev/ttyUSB3", logname="chad-test_bdk_boot_crb2.log")
        boot_test(cnx)
        dram_test(cnx)
        cnx.close()

main()
