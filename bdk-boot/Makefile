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

$(FATFS_IMG): $(BOOT_STUB_BIN) $(DIAGNOSTICS_BIN) lua/*
	# Create empty 3.5MB image file
	dd if=/dev/zero of=$(FATFS_IMG) bs=1k count=3584 2>/dev/null

	# Create FAT filesystem in image file
	$(BDK_ROOT)/bin/fatfs-tool -q -i $(FATFS_IMG) mkfs

	# Copy stage 2 image into FAT filesystem
	$(BDK_ROOT)/bin/fatfs-tool -q -i $(FATFS_IMG) cp $(DIAGNOSTICS_BIN) /

	# Add all the Lua files to the FAT fs
	$(BDK_ROOT)/bin/fatfs-tool -q -i $(FATFS_IMG) mkdir /lua
	$(BDK_ROOT)/bin/fatfs-tool -q -i $(FATFS_IMG) cp lua/*.lua /lua
	$(BDK_ROOT)/bin/fatfs-tool -q -i $(FATFS_IMG) cp default.cfg /

$(IMAGE_NAME).bin: $(BOOT_STUB_BIN) $(STAGE2_BIN) $(FATFS_IMG)
	#
	# 1) 0x000000: 64KB unused by Thunder
	cat ptable-16MB-0x080000-0x300000-2.5M.img /dev/zero | head -q -c 65536 > $(IMAGE_NAME).bin
	# 2) 0x010000: 64KB of CVM_CLIB header
	echo -n CVM_CLIB | cat - /dev/zero | head -q -c 65536 >> $(IMAGE_NAME).bin
	# 3) 0x020000: 192KB of chainloader image (non-trusted)
	cat $(BOOT_STUB_BIN) /dev/zero | head -q -c 196608 >> $(IMAGE_NAME).bin
	# 4) 0x050000: 192KB of chainloader image (trusted)
	cat $(BOOT_STUB_BIN) /dev/zero | head -q -c 196608 >> $(IMAGE_NAME).bin
	# 5) 0x080000: 3.5MB FAT filesystem
	cat $(FATFS_IMG) /dev/zero | head -q -c 3670016 >> $(IMAGE_NAME).bin
	# You need to install ATF starting at 0x400000


$(DIAGNOSTICS): diagnostics.o $(BDK_ROOT)/libbdk/libbdk.a
$(BOOT_STUB):   boot-stub.o   $(BDK_ROOT)/libbdk/libbdk.a

clean:
	rm -f *.o *.map *.bin $(DIAGNOSTICS) $(BOOT_STUB) $(IMAGE_NAME).bin $(DIR)/$(IMAGE_NAME).bin $(FATFS_IMG)
