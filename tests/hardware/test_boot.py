import boards
import connection
import test_dram

def wait_for_bootstub_messages(cnx):
    cnx.powerCycle()
    cnx.waitfor("Cavium SOC", timeout=20)
    cnx.match("Locking L2 cache")
    cnx.match("PASS: CRC32 verification")
    cnx.match("Transferring to thread scheduler")
    cnx.match("================")
    cnx.match("Cavium Boot Stub")
    cnx.match("================")
    cnx.matchRE("Firmware Version: .+\n")
    cnx.matchRE("BDK Version: .+\n")
    cnx.matchRE("Board Model:    .+\n")
    cnx.matchRE("Board Revision: .+\n")
    cnx.matchRE("Board Serial:   .+\n")
    cnx.match("Node:  0")
    try:
        cnx.match("(Fixed)")
    except:
        pass
    cnx.matchRE("Chip:  0xa1 Pass [1-7]\\.[0-7]")
    cnx.matchRE("SKU:   CN[0-9]+-[0-9]+BG[0-9]+-[A-Z]+(-PR)?(-[Y-Z][0-8]*)?-G")
    cnx.match("L2:    16384 KB")
    cnx.matchRE("RCLK:  [0-9]+ Mhz")
    cnx.matchRE("SCLK:  [0-9]+ Mhz")
    cnx.match("Boot:  SPI24(5)")
    try:
        cnx.match("VRM:   Disabled")
    except:
        cnx.match("VRM:   Enabled")
    cnx.match("Trust: Disabled, Non-secure Boot")
    cnx.matchRE("CCPI: .+\n")
    cnx.match("Press 'B' within 10 seconds for boot menu")
    cnx.write("B")

    cnx.match("=================================")
    cnx.match("Boot Options")
    cnx.match("=================================")
    cnx.match("N) Boot Normally")
    cnx.match("S) Enter Setup")
    cnx.match("D) Enter Diagnostics")
    cnx.match("E) Enter Diagnostics, skipping Setup")
    cnx.match("F) Select Image from Flash")
    cnx.match("X) Upload File to FatFS using Xmodem")
    cnx.match("W) Burn boot flash using Xmodem")
    cnx.match("U) Change baud rate and flow control")
    cnx.match("R) Reboot")
    cnx.match("Choice:")
    cnx.write("D")
    cnx.match("D")
    cnx.match("Loading image file '/fatfs/init.bin'")
    cnx.match("---")
    # Escape sequence here, hence wait below
    cnx.waitfor("Cavium SOC")
    cnx.match("Locking L2 cache")
    cnx.match("PASS: CRC32 verification")
    cnx.match("Transferring to thread scheduler")
    cnx.match("Using configuration from previous image")
    cnx.match("===========")
    cnx.match("Cavium Init")
    cnx.match("===========")
    cnx.matchRE("BDK Version: .+\n")
    cnx.matchRE("N0.LMC0 Configuration Completed: [0-9]+ MB", timeout=30)
    cnx.matchRE("N0.LMC1 Configuration Completed: [0-9]+ MB")
    cnx.matchRE("N0.LMC2 Configuration Completed: [0-9]+ MB")
    cnx.matchRE("N0.LMC3 Configuration Completed: [0-9]+ MB")
    cnx.matchRE("Node 0: DRAM: [0-9]+ MB, [0-9]+ MHz, DDR[34] [UR]DIMM")
    try:
        cnx.match("Starting CCPI links")
    except:
        pass
    if cnx.multinode:
        cnx.match("N0.CCPI Lanes([] is good):[0][1][2][3][4][5][6][7][8][9][10][11][12][13][14][15][16][17][18][19][20][21][22][23]", timeout=30)
        cnx.match("N1.CCPI Lanes([] is good):[0][1][2][3][4][5][6][7][8][9][10][11][12][13][14][15][16][17][18][19][20][21][22][23]")
        cnx.match("Node:  1")
        try:
            cnx.match("(Fixed)")
        except:
            pass
        cnx.matchRE("Chip:  0xa1 Pass [1-2]\\.[0-1]")
        cnx.matchRE("SKU:   CN[0-9]+-[0-9]+BG[0-9]+-[A-Z]+(-PR)?(-[Y-Z][0-8]*)?-G")
        cnx.match("L2:    16384 KB")
        cnx.matchRE("RCLK:  [0-9]+ Mhz")
        cnx.matchRE("SCLK:  [0-9]+ Mhz")
        cnx.match("Boot:  SPI24(5)")
        try:
            cnx.match("VRM:   Disabled")
        except:
            cnx.match("VRM:   Enabled")
        cnx.match("Trust: Disabled")
        cnx.matchRE("CCPI: .+\n")
        cnx.matchRE("N1.LMC0 Configuration Completed: [0-9]+ MB")
        cnx.matchRE("N1.LMC1 Configuration Completed: [0-9]+ MB")
        cnx.matchRE("N1.LMC2 Configuration Completed: [0-9]+ MB")
        cnx.matchRE("N1.LMC3 Configuration Completed: [0-9]+ MB")
        cnx.matchRE("Node 1: DRAM: [0-9]+ MB, [0-9]+ MHz, DDR[34] [UR]DIMM", timeout=30)
    for pcie in range(2*5):
        try:
            cnx.matchRE("N[01]\\.PCIe[0-9]: Link .+\n", timeout=5)
        except:
            break
    cnx.match("Loading image file '/fatfs/diagnostics.bin'")
    cnx.match("---")

def wait_for_bdk_boot(cnx):
    # Escape sequence here, hence wait below
    cnx.waitfor("Cavium SOC")
    cnx.match("PASS: CRC32 verification")
    cnx.match("Transferring to thread scheduler")
    cnx.match("Using configuration from previous image")
    cnx.match("Lua 5.2.0  Copyright (C) 1994-2011 Lua.org, PUC-Rio")
    cnx.match("Cavium Diagnostics")
    cnx.match("Copyright (C) 2010-2016 Cavium Inc.")
    cnx.matchRE("BDK Version: .+\n")
    cnx.match("=================================")
    cnx.match("Main Menu")
    cnx.match("=================================")
    # Extra output allowed here
    cnx.waitfor("(INS)Menu choice []:")
    cnx.sendEcho("keys")
    cnx.match("Selection not valid. Please choose an entry from the list above.")

def wait_for_main_menu(cnx):
    cnx.waitfor("=================================")
    cnx.match("Main Menu")
    cnx.match("=================================")
    cnx.match("cfg) Display current configuration")
    cnx.match("qlm) SERDES configuration")
    cnx.match("file) File options")
    cnx.match("ddr) DDR options")
    cnx.match("pcie) PCIe options")
    cnx.match("twsi) TWSI options")
    cnx.match("smi) SMI/MDIO options")
    cnx.match("mpi) SPI/MPI options")
    cnx.match("emmc) eMMC/SD options")
    cnx.match("sata) SATA options")
    cnx.match("gpio) GPIO options")
    cnx.match("sgpio) SGPIO options")
    cnx.match("usb) USB options")
    cnx.match("ilua) Interactive Lua prompt")
    cnx.match("tg) Traffic Generator")
    cnx.match("burn) Power Burn options")
    cnx.match("ccpi) CCPI options")
    # Extra output allowed here
    cnx.waitfor("rbt) Reboot")
    cnx.match("(INS)Menu choice []:")

def boot_normal(cnx):
    wait_for_bootstub_messages(cnx)
    wait_for_bdk_boot(cnx)
    wait_for_main_menu(cnx)
