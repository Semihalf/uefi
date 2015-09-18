include $(BDK_ROOT)/libbdk/bdk.mk

DIR=$(BDK_ROOT)/target-bin

FATFS_IMG  = fatfs.bin

DIAGNOSTICS     = diagnostics
DIAGNOSTICS_BIN = diagnostics.bin
BOOT_STUB       = boot-stub
BOOT_STUB_BIN   = boot-stub.bin

IMAGE_NAME=bdk

.PHONY: all
all: $(DIR)/$(IMAGE_NAME).bin

# bdk-boot image
$(DIR)/$(IMAGE_NAME).bin: $(IMAGE_NAME).bin
	cp $(IMAGE_NAME).bin $(DIR)/$(IMAGE_NAME).bin

$(IMAGE_NAME).bin: $(BOOT_STUB_BIN) $(DIAGNOSTICS_BIN) lua/*.lua default.cfg
	if [ `stat -c %s $(BOOT_STUB_BIN)` -gt 196608 ]; then echo "ERROR: $(BOOT_STUB_BIN) image must be 192KB or less";exit 1;fi
	$(BDK_ROOT)/bin/bdk-create-fatfs-image -o $@ \
	    -0 $(BOOT_STUB_BIN) -1 $(DIAGNOSTICS_BIN) -2 $(DIAGNOSTICS_BIN) \
	    -l "lua/*.lua" -c default.cfg

$(DIAGNOSTICS): diagnostics.o $(BDK_ROOT)/libbdk/libbdk.a
$(BOOT_STUB):   boot-stub.o   $(BDK_ROOT)/libbdk/libbdk.a

clean:
	rm -f *.o *.map *.bin $(DIAGNOSTICS) $(BOOT_STUB) $(IMAGE_NAME).bin $(DIR)/$(IMAGE_NAME).bin $(FATFS_IMG)
