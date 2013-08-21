include $(BDK_ROOT)/libbdk/bdk.mk

IMAGES = bdk-full

BINS = $(IMAGES:%=%.bin)
TARGETS = $(IMAGES:%=$(BDK_ROOT)/target-bin/%-no-romfs.bin)

.PHONY: all
all: $(TARGETS) bdk-reset-rtl bdk-quick-boot.bin

$(BDK_ROOT)/target-bin/bdk-full-no-romfs.bin: bdk-full.bin
	cp $(^:%.bin=%) $(BDK_ROOT)/target-bin/$(^:%.bin=%)-no-romfs
	cp $(^:%.bin=%.map) $(BDK_ROOT)/target-bin/$(^:%.bin=%)-no-romfs.map
	cp $^ $(BDK_ROOT)/target-bin/$(^:%.bin=%)-no-romfs.bin

bdk-full: bdk-full.o $(BDK_ROOT)/libbdk/libbdk.a
bdk-quick-boot: bdk-quick-boot.o $(BDK_ROOT)/libbdk/libbdk.a

bdk-reset-rtl: bdk-reset-rtl.S
	$(CC) -nostdlib -nostartfiles -Ttext=0xBFC00000 -o $@ $^

clean:
	rm -f *.o *.map *.bin  bdk-reset-rtl $(IMAGES) $(BDK_ROOT)/target-bin/*-no-romfs*

