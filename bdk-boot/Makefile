include $(BDK_ROOT)/libbdk/bdk.mk

IMAGES = bdk-full bdk-minimal

BINS = $(IMAGES:%=%.bin)
TARGETS = $(IMAGES:%=$(BDK_ROOT)/target-bin/%-no-romfs.bin)

.PHONY: all
all: $(TARGETS) bdk-reset-rtl

$(TARGETS): $(BINS)
	for f in $(IMAGES); do \
		cp $$f $(BDK_ROOT)/target-bin/$$f-no-romfs; \
		cp $$f.map $(BDK_ROOT)/target-bin/$$f-no-romfs.map; \
		cp $$f.bin $(BDK_ROOT)/target-bin/$$f-no-romfs.bin; \
	done

bdk-full: bdk-full.o bdk-common.o $(BDK_ROOT)/libbdk/libbdk.a
bdk-minimal: bdk-minimal.o bdk-common.o $(BDK_ROOT)/libbdk/libbdk.a

bdk-reset-rtl: bdk-reset-rtl.S
	$(CC) -nostdlib -nostartfiles -Ttext=0xBFC00000 -o $@ $^

clean:
	rm -f *.o *.map *.bin  bdk-reset-rtl $(IMAGES) $(BDK_ROOT)/target-bin/*-no-romfs*

