include $(BDK_ROOT)/libbdk/bdk.mk

DIR=$(BDK_ROOT)/target-bin
NORMAL=normal-crb-2s

.PHONY: all
all: ${DIR}/${NORMAL}.bin ${DIR}/${NORMAL}-node1.bin

#
# Rules for node 0 boot stub
#
${DIR}/${NORMAL}.bin: ${NORMAL}.bin
	cp ${NORMAL}.bin ${DIR}/${NORMAL}.bin

stage1.bin: boot-stub.bin
	if [ `stat -c %s $^` -gt 196608 ]; then echo "ERROR: $^ image must be 192KB or less";exit 1;fi
	${BDK_ROOT}/bin/bdk-update-romfs stage1.bin boot-stub.bin

stage2.bin: diagnostics.bin lua/*
	${BDK_ROOT}/bin/bdk-update-romfs stage2.bin diagnostics.bin lua/*

${NORMAL}.bin: stage1.bin stage2.bin
	#
	# 1) 64KB unused by Thunder
	cat /dev/zero | head -q -c 65536 > ${NORMAL}.bin
	# 2) 64KB of CVM_CLIB header
	echo -n CVM_CLIB | cat - /dev/zero | head -q -c 65536 >> ${NORMAL}.bin
	# 3) 192KB of boot-stub image (non-trusted)
	cat stage1.bin /dev/zero | head -q -c 196608 >> ${NORMAL}.bin
	# 4) 192KB of boot-stub image (trusted)
	cat stage1.bin /dev/zero | head -q -c 196608 >> ${NORMAL}.bin
	# 5) 4MB-512KB of diagnostics
	cat stage2.bin >> ${NORMAL}.bin
	# 6) You need to install ATF starting at 4MB

diagnostics: diagnostics.o tuning.o $(BDK_ROOT)/libbdk/libbdk.a
boot-stub: boot-stub.o tuning.o $(BDK_ROOT)/libbdk/libbdk.a

#
# Rules for node 1 boot stub
#
${DIR}/${NORMAL}-node1.bin: ${NORMAL}-node1.bin
	cp ${NORMAL}-node1.bin ${DIR}/${NORMAL}-node1.bin

boot-stub-node1: BDK_LINK_ADDRESS=0x10000000000
boot-stub-node1: boot-stub.o $(BDK_ROOT)/libbdk/libbdk.a
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

${NORMAL}-node1.bin: boot-stub-node1.bin
	if [ `stat -c %s $^` -gt 196608 ]; then echo "ERROR: $^ image must be 192KB or less";exit 1;fi
	${BDK_ROOT}/bin/bdk-update-romfs stage1-node1.bin boot-stub-node1.bin
	#
	# 1) 64KB unused by Thunder
	cat /dev/zero | head -q -c 65536 > $@
	# 2) 64KB of CVM_CLIB header
	echo -n CVM_CLIB | cat - /dev/zero | head -q -c 65536 >> $@
	# 3) 192KB of boot-stub image (non-trusted)
	cat stage1-node1.bin /dev/zero | head -q -c 196608 >> $@
	# 4) 192KB of boot-stub image (trusted)
	cat stage1-node1.bin /dev/zero | head -q -c 196608 >> $@
	rm stage1-node1.bin

clean:
	rm -f *.o *.map *.bin boot-stub boot-stub-node1 diagnostics ${DIR}/${NORMAL}.bin ${DIR}/${NORMAL}-node1.bin

