include $(BDK_ROOT)/libbdk/bdk.mk

IMAGES = bdk-full bdk-minimal

BINS = $(IMAGES:%=%.bin)
TARGETS = $(IMAGES:%=$(BDK_ROOT)/target-bin/%-no-romfs.bin)

.PHONY: all
all: $(TARGETS) bdk-reset-rtl

$(BDK_ROOT)/target-bin/bdk-minimal-no-romfs.bin: bdk-minimal.bin
	cp $(^:%.bin=%) $(BDK_ROOT)/target-bin/$(^:%.bin=%)-no-romfs
	cp $(^:%.bin=%.map) $(BDK_ROOT)/target-bin/$(^:%.bin=%)-no-romfs.map
	cp $^ $(BDK_ROOT)/target-bin/$(^:%.bin=%)-no-romfs.bin

$(BDK_ROOT)/target-bin/bdk-full-no-romfs.bin: bdk-full.bin
	cp $(^:%.bin=%) $(BDK_ROOT)/target-bin/$(^:%.bin=%)-no-romfs
	cp $(^:%.bin=%.map) $(BDK_ROOT)/target-bin/$(^:%.bin=%)-no-romfs.map
	cp $^ $(BDK_ROOT)/target-bin/$(^:%.bin=%)-no-romfs.bin

bdk-full: bdk-full.o bdk-common.o $(BDK_ROOT)/libbdk/libbdk.a
bdk-minimal: bdk-minimal.o bdk-common.o $(BDK_ROOT)/libbdk/libbdk.a

bdk-reset-rtl: bdk-reset-rtl.S
	$(CC) -nostdlib -nostartfiles -Ttext=0xBFC00000 -o $@ $^

clean:
	rm -f *.o *.map *.bin  bdk-reset-rtl $(IMAGES) $(BDK_ROOT)/target-bin/*-no-romfs*

