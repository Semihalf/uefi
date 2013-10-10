include $(BDK_ROOT)/libbdk/bdk.mk

.PHONY: all
all: bdk-reset-rtl bdk-boot-nor-stage1-cn70xx.bin $(BDK_ROOT)/target-bin/bdk-full-no-romfs.bin

$(BDK_ROOT)/target-bin/bdk-full-no-romfs.bin: bdk-full-no-romfs.bin
	cp bdk-full-no-romfs $(BDK_ROOT)/target-bin/
	cp bdk-full-no-romfs.map $(BDK_ROOT)/target-bin/
	cp bdk-full-no-romfs.bin $(BDK_ROOT)/target-bin/

bdk-full-no-romfs: bdk-full-no-romfs.o $(BDK_ROOT)/libbdk/libbdk.a
bdk-boot-nor-stage1-cn70xx: bdk-boot-nor-stage1-cn70xx.o $(BDK_ROOT)/libbdk/libbdk.a

bdk-reset-rtl: bdk-reset-rtl.S
	$(CC) -nostdlib -nostartfiles -Ttext=0xBFC00000 -o $@ $^

clean:
	rm -f *.o *.map *.bin  bdk-reset-rtl bdk-full-no-romfs bdk-boot-nor-stage1-cn70xx $(BDK_ROOT)/target-bin/*-no-romfs*

