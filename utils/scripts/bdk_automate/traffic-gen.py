import connection

#
# Simple test to loop starting the BDK traffic-gen and checking network links
#
s = connection.Connection("/dev/ttyS13")
count = 0
while True:
    s.matchwait("Bringup and Diagnostic Kit (BDK)\r\n", timeout=30)
    s.matchline("Locking L2 cache")
    s.matchline("Transferring to thread scheduler")
    s.matchline("Performing common initialization")
    s.matchline("Enabling hardware flow control on UART0")
    s.matchline("WARNING: Not enabling hardware flow control on UART1 as CTS appears stuck")
    s.matchline("Switching to main")
    s.matchline("Lua 5.2.0  Copyright (C) 1994-2011 Lua.org, PUC-Rio")
    s.matchline("")
    s.matchline("Octeon Bringup and Diagnostic Kit")
    s.matchline("Copyright (C) 2010-2012 Cavium Networks")
    s.patternline("Version [0-9]{4}.[0-9]{2}-r[0-9]+")
    s.matchline("")
    s.readline() # The BDK send a line of terminal escape characters
    s.matchline("Configuring for the EBB6800")
    s.matchline("TFTP: Server started")
    s.matchline("Telnet: Server started")
    s.matchline("")
    s.matchline("=================================")
    s.matchline("Main Menu")
    s.matchline("=================================")
    s.matchline(" 1) Configuration options")
    s.matchline(" 2) File options")
    s.matchline(" 3) Flash options")
    s.matchline(" 4) DDR options")
    s.matchline(" 5) QLM options")
    s.matchline(" 6) PCIe options")
    s.matchline(" 7) TWSI options")
    s.matchline(" 8) SMI/MDIO options")
    s.matchline(" 9) GPIO options")
    s.matchline("10) Interactive Lua prompt")
    s.matchline("11) TCP/IP networking")
    s.matchline("12) Traffic Generator")
    s.matchline("13) Reboot")
    s.match("(INS)Menu choice []: ")
    s.writeEchol("keys")
    s.patternline("Invalid choice[.] Choose a number from 1 to [0-9]+")
    s.matchline("")
    s.matchline("=================================")
    s.matchline("Main Menu")
    s.matchline("=================================")
    s.matchline("  config) Configuration options")
    s.matchline("    file) File options")
    s.matchline("   flash) Flash options")
    s.matchline("     ddr) DDR options")
    s.matchline("     qlm) QLM options")
    s.matchline("    pcie) PCIe options")
    s.matchline("    twsi) TWSI options")
    s.matchline("     smi) SMI/MDIO options")
    s.matchline("    gpio) GPIO options")
    s.matchline("    ilua) Interactive Lua prompt")
    s.matchline("     net) TCP/IP networking")
    s.matchline("      tg) Traffic Generator")
    s.matchline("     rbt) Reboot")
    s.match("(INS)Menu choice []: ")
    s.writeEchol("tg")
    s.readline() # The BDK send a line of terminal escape characters
    s.matchline("")
    s.matchline("BDK Traffic Generator")
    s.matchline("")
    s.matchline("Type \"help\" for a list of commands")
    s.match("(INS)Command> ")
    s.delay(1) # Wait for aynchronous link status messages
    s.writeEchol("clear all")
    s.match("(INS)Command> ")
    s.writeEchol("link_speed all")
    s.matchline("Port XAUI00: link_speed = 10000")
    s.matchline("Port XAUI10: link_speed = 10000")
    s.matchline("Port XAUI30: link_speed = 20000")
    s.matchline("Port XAUI40: link_speed = 20000")
    s.matchline("Port LOOP00: link_speed = 10000")
    s.matchline("Port LOOP01: link_speed = 10000")
    s.matchline("Port LOOP02: link_speed = 10000")
    s.matchline("Port LOOP03: link_speed = 10000")
    s.matchline("Port LOOP04: link_speed = 10000")
    s.matchline("Port LOOP05: link_speed = 10000")
    s.matchline("Port LOOP06: link_speed = 10000")
    s.matchline("Port LOOP07: link_speed = 10000")
    s.matchline("Port MGMT00: link_speed = 1000")
    s.matchline("Port ILK00: link_speed = 23880")
    s.matchline("Port ILK01: link_speed = 23880")
    s.matchline("Port ILK02: link_speed = 23880")
    s.matchline("Port ILK03: link_speed = 23880")
    s.matchline("Port ILK04: link_speed = 23880")
    s.matchline("Port ILK05: link_speed = 23880")
    s.matchline("Port ILK06: link_speed = 23880")
    s.matchline("Port ILK07: link_speed = 23880")
    s.matchline("Port ILK10: link_speed = 23880")
    s.matchline("Port ILK11: link_speed = 23880")
    s.matchline("Port ILK12: link_speed = 23880")
    s.matchline("Port ILK13: link_speed = 23880")
    s.matchline("Port ILK14: link_speed = 23880")
    s.matchline("Port ILK15: link_speed = 23880")
    s.matchline("Port ILK16: link_speed = 23880")
    s.matchline("Port ILK17: link_speed = 23880")
    s.match("(INS)Command> ")
    PORT_LIST = ["XAUI00", "XAUI10", "XAUI30", "XAUI40", "ILK00", "ILK10"]
    PACKET_COUNT = 1000000
    PACKET_SIZE = 1500
    for port in PORT_LIST:
        s.writeEchol("tx_percent %s 2000" % port)
        s.match("(INS)Command> ")
        s.writeEchol("size %s %d" % (port, PACKET_SIZE))
        s.match("(INS)Command> ")
        s.writeEchol("count %s %d" % (port, PACKET_COUNT))
        s.match("(INS)Command> ", 6)
        s.writeEchol("start %s" % port)
        s.match("(INS)Command> ")
        s.writeEchol("sleep 2")
        s.matchline("Sleeping for 2 seconds")
        s.match("(INS)Command> ", 3)
    for port in PORT_LIST:
        s.writeEchol("tx_packets_total %s" % port)
        s.matchline("Port %s: tx_packets_total = %d" % (port, PACKET_COUNT))
        s.match("(INS)Command> ")
        s.writeEchol("rx_packets_total %s" % port)
        s.matchline("Port %s: rx_packets_total = %d" % (port, PACKET_COUNT))
        s.match("(INS)Command> ")
        s.writeEchol("tx_octets_total %s" % port)
        s.matchline("Port %s: tx_octets_total = %d" % (port, PACKET_COUNT * (PACKET_SIZE + 4)))
        s.match("(INS)Command> ")
        s.writeEchol("rx_octets_total %s" % port)
        s.matchline("Port %s: rx_octets_total = %d" % (port, PACKET_COUNT * (PACKET_SIZE + 4)))
        s.match("(INS)Command> ")
        s.writeEchol("rx_errors %s" % port)
        s.matchline("Port %s: rx_errors = 0" % port)
        s.match("(INS)Command> ")
        s.writeEchol("rx_validation_errors %s" % port)
        s.matchline("Port %s: rx_validation_errors = 0" % port)
        s.match("(INS)Command> ")
    s.writeEchol("reboot")
    count = count + 1
    print "Loop", count

