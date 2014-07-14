import os
import octeon_sim

BDK_ROOT= os.environ["BDK_ROOT"]
sim_args = [
    "-ld0:%s/target-bin/original/bdk-full-no-romfs" % BDK_ROOT,
    "-ld0x1fc00000:%s/target-bin/bdk-boot-cn78xx.bin" % BDK_ROOT,
    "-ld0:0x1000000",
    "-modes=fastboot,pass1",
    "-noperf",
    "-quiet",
    "-numcores=2",
    "-maxcycles=1000000000",
    ]

sim = octeon_sim.Simulator("test-loop-sim.log", sim_args)
sim.waitFor("Lua 5.2.0  Copyright (C) 1994-2011 Lua.org, PUC-Rio")
sim.waitFor("Octeon Bringup and Diagnostic Kit")
sim.waitFor("Copyright (C) 2010-2014 Cavium Networks")
sim.waitFor("Version")
sim.waitFor("Menu choice []: ")
sim.send("keys\r")
sim.waitFor("Menu choice []: ")
sim.send("tg\r")
sim.waitFor("BDK Traffic Generator")
sim.send("default loop0\r")
sim.waitFor("Default ports: LOOP0")
sim.send("count 100\r")
sim.send("tx_packets_total\r")
sim.waitFor("Port LOOP0: tx_packets_total = 0")
sim.send("rx_packets_total\r")
sim.waitFor("Port LOOP0: rx_packets_total = 0")
sim.send("start\r")
sim.send("\r")
sim.send("tx_packets_total\r")
sim.waitFor("Port LOOP0: tx_packets_total = 100")
sim.send("rx_packets_total\r")
sim.waitFor("Port LOOP0: rx_packets_total = 100")
sim.send("tx_octets_total\r")
sim.waitFor("Port LOOP0: tx_octets_total = 6000")
sim.send("rx_octets_total\r")
sim.waitFor("Port LOOP0: rx_octets_total = 6000")
sim.send("reboot\r")
sim.waitDie()




