include $(BDK_ROOT)/libbdk/bdk.mk

DIR=$(BDK_ROOT)/target-bin

${DIR}/bdk.bin: bdk.bin
	cp bdk.bin ${DIR}/bdk.bin

stage1.bin: boot-stub.bin
	if [ `stat -c %s $^` -gt 196608 ]; then echo "ERROR: $^ image must be 192KB or less";exit 1;fi
	${BDK_ROOT}/bin/bdk-update-romfs stage1.bin boot-stub.bin

stage2.bin: diagnostics.bin lua/*
	${BDK_ROOT}/bin/bdk-update-romfs stage2.bin diagnostics.bin lua/*

bdk.bin: stage1.bin stage2.bin
	#
	# 1) 64KB unused by Thunder
	cat /dev/zero | head -q -c 65536 > bdk.bin
	# 2) 64KB of CVM_CLIB header
	echo -n CVM_CLIB | cat - /dev/zero | head -q -c 65536 >> bdk.bin
	# 3) 192KB of boot-stub image (non-trusted)
	cat stage1.bin /dev/zero | head -q -c 196608 >> bdk.bin
	# 4) 192KB of boot-stub image (trusted)
	cat stage1.bin /dev/zero | head -q -c 196608 >> bdk.bin
	# 5) 8MB-512KB of diagnostics
	cat stage2.bin >> bdk.bin

diagnostics: diagnostics.o $(BDK_ROOT)/libbdk/libbdk.a
boot-stub: boot-stub.o $(BDK_ROOT)/libbdk/libbdk.a

clean:
	rm -f *.o *.map *.bin boot-stub diagnostics ${DIR}/bdk.bin

