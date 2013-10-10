include $(BDK_ROOT)/libbdk/bdk.mk

DIR=$(BDK_ROOT)/target-bin/original

TARGETS := bdk-reset-rtl
TARGETS += bdk-full-no-romfs
TARGETS += ${DIR}/bdk-full-no-romfs.bin
TARGETS += bdk-boot-nor-stage1-cn70xx
TARGETS += ${DIR}/bdk-boot-nor-stage1-cn70xx.bin

.PHONY: all
all: ${TARGETS}

${DIR}/bdk-full-no-romfs.bin: bdk-full-no-romfs.bin
	cp bdk-full-no-romfs ${DIR}/
	cp bdk-full-no-romfs.map ${DIR}/
	cp bdk-full-no-romfs.bin ${DIR}/

${DIR}/bdk-boot-nor-stage1-cn70xx.bin: bdk-boot-nor-stage1-cn70xx.bin
	cp bdk-boot-nor-stage1-cn70xx.bin ${DIR}/

bdk-full-no-romfs: bdk-full-no-romfs.o $(BDK_ROOT)/libbdk/libbdk.a
bdk-boot-nor-stage1-cn70xx: bdk-boot-nor-stage1-cn70xx.o $(BDK_ROOT)/libbdk/libbdk.a

bdk-reset-rtl: bdk-reset-rtl.S
	$(CC) -nostdlib -nostartfiles -Ttext=0xBFC00000 -o $@ $^

clean:
	rm -f *.o *.map *.bin ${TARGETS} ${DIR}/bdk-*

