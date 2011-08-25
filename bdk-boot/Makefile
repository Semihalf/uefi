include $(BDK_ROOT)/libbdk/bdk.mk

IMAGES = bdk-full bdk-minimal

BINS = $(IMAGES:%=%.bin)
TARGETS = $(IMAGES:%=$(BDK_ROOT)/target-bin/%-no-romfs.bin)

$(TARGETS): $(BINS)
	for f in $(IMAGES); do \
		cp $$f $(BDK_ROOT)/target-bin/$$f-no-romfs; \
		cp $$f.map $(BDK_ROOT)/target-bin/$$f-no-romfs.map; \
		cp $$f.bin $(BDK_ROOT)/target-bin/$$f-no-romfs.bin; \
	done

bdk-full: bdk-full.o bdk-common.o $(BDK_ROOT)/libbdk/libbdk.a
bdk-minimal: bdk-minimal.o bdk-common.o $(BDK_ROOT)/libbdk/libbdk.a

clean:
	rm -f *.o *.map *.bin $(IMAGES) $(BDK_ROOT)/target-bin/*-no-romfs*

