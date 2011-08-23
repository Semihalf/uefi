include $(BDK_ROOT)/libbdk/bdk.mk

$(BDK_ROOT)/target-bin/bdk-no-romfs.bin: bdk-base.bin
	cp bdk-base $(BDK_ROOT)/target-bin/bdk-no-romfs
	cp bdk-base.map $(BDK_ROOT)/target-bin/bdk-no-romfs.map
	cp bdk-base.bin $(BDK_ROOT)/target-bin/bdk-no-romfs.bin

bdk-base.bin: bdk-base
bdk-base: bdk-base.o $(BDK_ROOT)/libbdk/libbdk.a

clean:
	rm -f *.o *.map bdk-base bdk-base.bin $(BDK_ROOT)/target-bin/bdk-no-romfs.bin

