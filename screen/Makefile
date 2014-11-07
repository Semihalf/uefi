include $(BDK_ROOT)/libbdk/bdk.mk

DIR=$(BDK_ROOT)/target-bin

${DIR}/screen-standalone.bin: screen-standalone.bin
	cp screen-standalone.bin ${DIR}/screen-standalone.bin

stage1.bin: boot-stub.bin
	${BDK_ROOT}/bin/bdk-update-romfs stage1.bin boot-stub.bin

stage2.bin: screen.bin lua/*
	${BDK_ROOT}/bin/bdk-update-romfs stage2.bin screen.bin lua/*

screen-standalone.bin: stage1.bin stage2.bin
	#
	# 1) 64KB unused by Thunder
	cat /dev/zero | head -q -c 65536 > screen-standalone.bin
	# 2) 64KB of CVM_CLIB header
	echo -n CVM_CLIB | cat - /dev/zero | head -q -c 65536 >> screen-standalone.bin
	# 3) 192KB of boot-stub image (non-trusted)
	cat stage1.bin /dev/zero | head -q -c 196608 >> screen-standalone.bin
	# 4) 192KB of boot-stub image (trusted)
	cat stage1.bin /dev/zero | head -q -c 196608 >> screen-standalone.bin
	# 5) 4MB-512KB of diagnostics
	cat stage2.bin /dev/zero | head -q -c 3670016 >> screen-standalone.bin
	# 6) You need to install ATF starting at 4MB

screen: screen.o $(BDK_ROOT)/libbdk/libbdk.a
boot-stub: boot-stub.o $(BDK_ROOT)/libbdk/libbdk.a

clean:
	rm -f *.o *.map *.bin boot-stub screen ${DIR}/screen-standalone.bin

.PHONY: run-screen
run-screen:
	UART0PORT=2000 UART1PORT=2001 BIN_IMAGE=screen-standalone.bin SYMBOL_IMAGE=screen $(ASIM)/asim -e $(BDK_ROOT)/bdk.asim


