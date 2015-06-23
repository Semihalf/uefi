include $(BDK_ROOT)/libbdk/bdk.mk

DIR=$(BDK_ROOT)/target-bin
IMAGE_NAME=chainboot
IMAGE_NAME_NONFAT=chainboot-nonfat

.PHONY: all
all: ${DIR}/${IMAGE_NAME}.bin ${DIR}/${IMAGE_NAME_NONFAT}.bin ${DIR}/${IMAGE_NAME}-node1.bin

#
# Rules for node 0 boot stub
#
${DIR}/${IMAGE_NAME}.bin: ${IMAGE_NAME}.bin
	cp ${IMAGE_NAME}.bin ${DIR}/${IMAGE_NAME}.bin

${DIR}/${IMAGE_NAME_NONFAT}.bin: ${IMAGE_NAME_NONFAT}.bin
	cp ${IMAGE_NAME_NONFAT}.bin ${DIR}/${IMAGE_NAME_NONFAT}.bin

# Initial stage 0 chainloader
stage0.bin: chainloader.bin
	if [ `stat -c %s $^` -gt 196608 ]; then echo "ERROR: $^ image must be 192KB or less";exit 1;fi
	cp chainloader.bin stage0.bin

# BDK image
stage1.bin: boot-stub.bin
	if [ `stat -c %s $^` -gt 524288 ]; then echo "ERROR: $^ image must be 512KB or less";exit 1;fi
	${BDK_ROOT}/bin/bdk-update-romfs stage1.bin boot-stub.bin

# Diagnostics image
stage2.bin: diagnostics.bin lua/*
	${BDK_ROOT}/bin/bdk-update-romfs stage2.bin diagnostics.bin lua/*

${IMAGE_NAME}.bin: stage0.bin stage1.bin stage2.bin
	#
	# 1) 0x000000: 64KB unused by Thunder
	cat /dev/zero | head -q -c 65536 > ${IMAGE_NAME}.bin
	# 2) 0x010000: 64KB of CVM_CLIB header
	echo -n CVM_CLIB | cat - /dev/zero | head -q -c 65536 >> ${IMAGE_NAME}.bin
	# 3) 0x020000: 192KB of chainloader image (non-trusted)
	cat stage0.bin /dev/zero | head -q -c 196608 >> ${IMAGE_NAME}.bin
	# 4) 0x050000: 192KB of chainloader image (trusted)
	cat stage0.bin /dev/zero | head -q -c 196608 >> ${IMAGE_NAME}.bin
	# 5) 0x080000: 512k of BDK image
	cat stage1.bin /dev/zero | head -q -c 524288 >> ${IMAGE_NAME}.bin
	# 6) 0x100000: 1.5MB of diagnostics
	cat stage2.bin /dev/zero | head -q -c 1572864 >> ${IMAGE_NAME}.bin
	# 7) 0x280000: 512k of FAT filesystem image
	gunzip -c fat-512k.img.gz >> ${IMAGE_NAME}.bin
	# 8) 0x300000: Free space until 0x400000
	# You need to install ATF starting at 0x400000

${IMAGE_NAME_NONFAT}.bin: stage0.bin stage1.bin stage2.bin
	#
	# 1) 0x000000: 64KB unused by Thunder
	cat /dev/zero | head -q -c 65536 > ${IMAGE_NAME_NONFAT}.bin
	# 2) 0x010000: 64KB of CVM_CLIB header
	echo -n CVM_CLIB | cat - /dev/zero | head -q -c 65536 >> ${IMAGE_NAME_NONFAT}.bin
	# 3) 0x020000: 192KB of chainloader image (non-trusted)
	cat stage0.bin /dev/zero | head -q -c 196608 >> ${IMAGE_NAME_NONFAT}.bin
	# 4) 0x050000: 192KB of chainloader image (trusted)
	cat stage0.bin /dev/zero | head -q -c 196608 >> ${IMAGE_NAME_NONFAT}.bin
	# 5) 0x080000: 512k of BDK image
	cat stage1.bin /dev/zero | head -q -c 524288 >> ${IMAGE_NAME_NONFAT}.bin
	# 6) 0x100000: 1.5MB of diagnostics
	cat stage2.bin /dev/zero | head -q -c 1572864 >> ${IMAGE_NAME_NONFAT}.bin
	# 7) 0x300000: Free space until 0x400000
	# You need to install ATF starting at 0x400000

chainloader: chainloader.o $(BDK_ROOT)/libbdk/libbdk.a
diagnostics: diagnostics.o tuning.o $(BDK_ROOT)/libbdk/libbdk.a
boot-stub: boot-stub.o tuning.o $(BDK_ROOT)/libbdk/libbdk.a

#
# Rules for node 1 boot stub
#
${DIR}/${IMAGE_NAME}-node1.bin: ${IMAGE_NAME}-node1.bin
	cp ${IMAGE_NAME}-node1.bin ${DIR}/${IMAGE_NAME}-node1.bin

boot-stub-node1: BDK_LINK_ADDRESS=0x10000000000
boot-stub-node1: boot-stub.o $(BDK_ROOT)/libbdk/libbdk.a
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

${IMAGE_NAME}-node1.bin: boot-stub-node1.bin
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
	rm -f *.o *.map *.bin boot-stub boot-stub-node1 diagnostics ${DIR}/${IMAGE_NAME}.bin ${DIR}/${IMAGE_NAME_NONFAT}.bin ${DIR}/${IMAGE_NAME}-node1.bin

