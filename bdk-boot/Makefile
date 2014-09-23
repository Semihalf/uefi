include $(BDK_ROOT)/libbdk/bdk.mk

DIR=$(BDK_ROOT)/target-bin/original

TARGETS := bdk-full-no-romfs
TARGETS += ${DIR}/bdk-full-no-romfs.bin
TARGETS += bdk-stage1
TARGETS += ${DIR}/bdk-stage1.bin

.PHONY: all
all: ${TARGETS}

${DIR}/bdk-full-no-romfs.bin: bdk-full-no-romfs.bin
	mkdir -p ${DIR}
	cp bdk-full-no-romfs ${DIR}/
	cp bdk-full-no-romfs.map ${DIR}/
	cp bdk-full-no-romfs.bin ${DIR}/

${DIR}/bdk-stage1.bin: bdk-stage1.bin
	mkdir -p ${DIR}
	cp bdk-stage1 ${DIR}/
	cp bdk-stage1.map ${DIR}/
	cp bdk-stage1.bin ${DIR}/

bdk-full-no-romfs: bdk-full-no-romfs.o $(BDK_ROOT)/libbdk/libbdk.a
bdk-stage1: bdk-stage1.o $(BDK_ROOT)/libbdk/libbdk.a

clean:
	rm -f *.o *.map *.bin ${TARGETS} ${DIR}/bdk-*

