import boards
import connection
import test_dram

def wait_for_bootstub_messages(cnx):
    cnx.powerCycle()
    cnx.waitfor("Cavium THUNDERX", timeout=20)
    cnx.match("PASS: CRC32 verification")
    cnx.matchRE("BDK version: 201[5-9].[0-2][0-9]-r")
    cnx.waitfor("=========================")
    cnx.match("Cavium THUNDERX Boot Stub")
    cnx.match("=========================")
    cnx.match("Node:  0")
    try:
        cnx.match("(Fixed)")
    except:
        pass
    cnx.match("Chip:  0xa1 Pass 1.0")
    cnx.match("L2:    16384 KB")
    cnx.matchRE("RCLK:  [0-9]+ Mhz")
    cnx.matchRE("SCLK:  [0-9]+ Mhz")
    cnx.match("Boot:  SPI24(5)")
    cnx.match("VRM:   Disabled")
    cnx.match("Trust: Disabled")
    cnx.matchRE("Node 0: DRAM: [0-9]+ MB, [0-9]+ MHz")
    if cnx.multinode:
        try:
            cnx.match("N0.CCPI Applying lane reversal")
        except:
            pass
        cnx.match("N0.CCPI Lanes([] is good):[0][1][2][3][4][5][6][7][8][9][10][11][12][13][14][15][16][17][18][19][20][21][22][23]")
        cnx.match("N1.CCPI Lanes([] is good):[0][1][2][3][4][5][6][7][8][9][10][11][12][13][14][15][16][17][18][19][20][21][22][23]")
        cnx.match("Node:  1")
        try:
            cnx.match("(Fixed)")
        except:
            pass
        cnx.match("Chip:  0xa1 Pass 1.0")
        cnx.match("L2:    16384 KB")
        cnx.matchRE("RCLK:  [0-9]+ Mhz")
        cnx.matchRE("SCLK:  [0-9]+ Mhz")
        cnx.match("Boot:  SPI24(5)")
        cnx.match("VRM:   Disabled")
        cnx.match("Trust: Disabled")
        cnx.matchRE("Node 1: DRAM: [0-9]+ MB, [0-9]+ MHz", timeout=20)
    else:
        cnx.match("Node 1: Not found, skipping DRAM init")
    cnx.waitfor("Press 'D' within 3 seconds to boot diagnostics", timeout=5)
    cnx.write("D")
    cnx.match("Loading image at 0x80000")
    cnx.match("Verifying image")
    cnx.match("Putting all cores except this one in reset")
    cnx.match("Jumping to image at 0x3a180")
    cnx.match("---")

def wait_for_bdk_boot(cnx):
    cnx.match("Cavium THUNDERX")
    cnx.match("PASS: CRC32 verification")
    cnx.match("Lua 5.2.0  Copyright (C) 1994-2011 Lua.org, PUC-Rio")
    cnx.match("THUNDERX Diagnostics")
    cnx.match("Copyright (C) 2010-2014 Cavium Inc.")
    cnx.matchRE("Version 201[5-9].[0-2][0-9]-r")
    cnx.waitforRE("Configuring for the [A-Za-z0-9-]+")
    cnx.waitfor("=================================")
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
    # Extra output allowed here
    cnx.waitfor("(INS)Menu choice []:")
    cnx.sendEcho("keys")
    cnx.match("Invalid choice. Choose a number from 1 to")

def wait_for_main_menu(cnx):
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
    # Extra output allowed here
    cnx.waitfor("(INS)Menu choice []:")

def boot_normal(cnx):
    wait_for_bootstub_messages(cnx)
    wait_for_bdk_boot(cnx)
    wait_for_main_menu(cnx)
