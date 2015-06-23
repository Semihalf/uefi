include $(BDK_ROOT)/libbdk/bdk.mk

DIR=$(BDK_ROOT)/target-bin
IMAGE_NAME=chainboot

.PHONY: all
all: ${DIR}/${IMAGE_NAME}.bin ${DIR}/${IMAGE_NAME}-node1.bin

#
# Rules for node 0 boot stub
#
${DIR}/${IMAGE_NAME}.bin: ${IMAGE_NAME}.bin
	cp ${IMAGE_NAME}.bin ${DIR}/${IMAGE_NAME}.bin

stage1.bin: boot-stub.bin
	if [ `stat -c %s $^` -gt 196608 ]; then echo "ERROR: $^ image must be 192KB or less";exit 1;fi
	${BDK_ROOT}/bin/bdk-update-romfs stage1.bin boot-stub.bin

stage2.bin: diagnostics.bin
	${BDK_ROOT}/bin/bdk-update-romfs stage2.bin diagnostics.bin

${IMAGE_NAME}.bin: stage1.bin stage2.bin
	#
	# 1) 64KB unused by Thunder
	cat /dev/zero | head -q -c 65536 > ${IMAGE_NAME}.bin
	# 2) 64KB of CVM_CLIB header
	echo -n CVM_CLIB | cat - /dev/zero | head -q -c 65536 >> ${IMAGE_NAME}.bin
	# 3) 192KB of boot-stub image (non-trusted)
	cat stage1.bin /dev/zero | head -q -c 196608 >> ${IMAGE_NAME}.bin
	# 4) 192KB of boot-stub image (trusted)
	cat stage1.bin /dev/zero | head -q -c 196608 >> ${IMAGE_NAME}.bin
	# 5) 512k-2.5MB FAT filesystem image
	cat fat-2mb.img >> ${IMAGE_NAME}.bin
	# 6) You need to install ATF starting at 4MB

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
	rm -f *.o *.map *.bin boot-stub boot-stub-node1 diagnostics ${DIR}/${IMAGE_NAME}.bin ${DIR}/${IMAGE_NAME}-node1.bin

