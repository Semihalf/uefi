include $(BDK_ROOT)/libbdk/bdk.mk

ifeq ($(SIM),cn78xx)
	NUMCORES=2
else
	NUMCORES=2
endif

clean:
	rm -f test-*.log

RUN_SIM_ARGS =
RUN_SIM_ARGS += -ld0:$(BDK_ROOT)/target-bin/original/bdk-full-no-romfs
RUN_SIM_ARGS += -ld0x1fc00000:$(BDK_ROOT)/target-bin/bdk-boot-cn78xx.bin
RUN_SIM_ARGS += -ld0:0x1000000
RUN_SIM_ARGS += -modes=fastboot,pass1
RUN_SIM_ARGS += -noperf
RUN_SIM_ARGS += -quiet
RUN_SIM_ARGS += -uart0=2020
RUN_SIM_ARGS += -numcores=$(NUMCORES)
RUN_SIM_ARGS += -maxcycles=1000000000

run:
	$(SIMULATOR) $(RUN_SIM_ARGS)

test:
	$(BDK_ROOT)/bin/bdk-uart-io -l test-uart.log -i input.txt &
	- $(SIMULATOR) $(RUN_SIM_ARGS) > test-sim.log
	grep -F "Lua 5.2.0  Copyright (C) 1994-2011 Lua.org, PUC-Rio" test-uart.log

	grep "Octeon Bringup and Diagnostic Kit" test-uart.log
	grep -F "Copyright (C) 2010-2013 Cavium Networks" test-uart.log
	grep "Version" test-uart.log

	grep "BDK Traffic Generator" test-uart.log
	grep "Default ports: LOOP0" test-uart.log
	grep "Port LOOP0: tx_packets_total = 0" test-uart.log
	grep "Port LOOP0: rx_packets_total = 0" test-uart.log
	grep "Port LOOP0: tx_packets_total = 100" test-uart.log
	grep "Port LOOP0: rx_packets_total = 100" test-uart.log
	grep "Port LOOP0: tx_octets_total = 6000" test-uart.log
	grep "Port LOOP0: rx_octets_total = 6000" test-uart.log

	grep "reboot" test-uart.log

