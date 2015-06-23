include $(BDK_ROOT)/libbdk/bdk.mk

DIR=$(BDK_ROOT)/target-bin
IMAGE_NAME=chainboot

.PHONY: all
all: ${DIR}/${IMAGE_NAME}.bin

#
# Rules for node 0 boot stub
#
${DIR}/${IMAGE_NAME}.bin: ${IMAGE_NAME}.bin
	cp ${IMAGE_NAME}.bin ${DIR}/${IMAGE_NAME}.bin

# Initial stage 0 chainloader
stage0.bin: chainloader.bin
	if [ `stat -c %s $^` -gt 196608 ]; then echo "ERROR: $^ image must be 192KB or less";exit 1;fi
	cp chainloader.bin stage0.bin

# BDK image
stage1.bin: boot-stub.bin
	${BDK_ROOT}/bin/bdk-update-romfs stage1.bin boot-stub.bin

# Diagnostics image
stage2.bin: diagnostics.bin lua/*
	${BDK_ROOT}/bin/bdk-update-romfs stage2.bin diagnostics.bin lua/*

fatfs.bin: stage1.bin stage2.bin
	# Create empty 2.5MB image file
	dd if=/dev/zero of=fatfs.bin bs=1k count=2560 status=none
	# Create FAT filesystem in image file
	${BDK_ROOT}/bin/fatfs-tool -i fatfs.bin mkfs
	# Copy stage 1 & 2 images into FAT filesystem
	${BDK_ROOT}/bin/fatfs-tool -i fatfs.bin put stage1.bin
	${BDK_ROOT}/bin/fatfs-tool -i fatfs.bin put stage2.bin

${IMAGE_NAME}.bin: stage0.bin stage1.bin stage2.bin fatfs.bin
	#
	# 1) 0x000000: 64KB unused by Thunder
	cat ptable-16MB-0x080000-0x300000-2.5M.img /dev/zero | head -q -c 65536 > ${IMAGE_NAME}.bin
	# 2) 0x010000: 64KB of CVM_CLIB header
	echo -n CVM_CLIB | cat - /dev/zero | head -q -c 65536 >> ${IMAGE_NAME}.bin
	# 3) 0x020000: 192KB of chainloader image (non-trusted)
	cat stage0.bin /dev/zero | head -q -c 196608 >> ${IMAGE_NAME}.bin
	# 4) 0x050000: 192KB of chainloader image (trusted)
	cat stage0.bin /dev/zero | head -q -c 196608 >> ${IMAGE_NAME}.bin
	# 5) 0x080000: 2.5MB FAT filesystem
	cat fatfs.bin /dev/zero | head -q -c 2621440 >> ${IMAGE_NAME}.bin
	# 6) 0x300000: Free space until 0x400000
	# You need to install ATF starting at 0x400000

chainloader: chainloader.o $(BDK_ROOT)/libbdk/libbdk.a
diagnostics: diagnostics.o tuning.o $(BDK_ROOT)/libbdk/libbdk.a
boot-stub: boot-stub.o tuning.o $(BDK_ROOT)/libbdk/libbdk.a

clean:
	rm -f *.o *.map *.bin boot-stub diagnostics ${DIR}/${IMAGE_NAME}.bin

