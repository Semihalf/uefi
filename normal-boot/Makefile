include $(BDK_ROOT)/libbdk/bdk.mk

DIR=$(BDK_ROOT)/target-bin

# Board specific modules and includes
ifndef BOARD_TYPE
$(info ********************************************************************************)
$(info * BOARD_TYPE not defined. Using default 'crb-2s')
$(info ********************************************************************************)
BOARD_TYPE=crb-2s
endif
BOARD_ROOT	= $(BOARD_TYPE)
BOARD_SRC	:= $(wildcard $(BOARD_ROOT)/*.c)
BOARD_OBJS	:= $(addsuffix .o, $(basename $(BOARD_SRC)))
CPPFLAGS 	+= -I $(BOARD_ROOT)

COMMON_SRC	:= $(wildcard *.c)
COMMON_OBJS	:= $(addsuffix .o, $(basename $(COMMON_SRC)))
COMMON_OBJS := $(foreach o,$(COMMON_OBJS),$(BOARD_ROOT)/$(o))
$(info $(COMMON_OBJS))

FATFS_IMG  = $(BOARD_ROOT)/fatfs.bin
STAGE0_BIN = $(BOARD_ROOT)/stage0.bin
STAGE1_BIN = $(BOARD_ROOT)/stage1.bin
STAGE2_BIN = $(BOARD_ROOT)/stage2.bin

CHAINLOADER     = $(BOARD_ROOT)/chainloader
CHAINLOADER_BIN = $(BOARD_ROOT)/chainloader.bin
BOOT_STUB       = $(BOARD_ROOT)/boot-stub
BOOT_STUB_BIN   = $(BOARD_ROOT)/boot-stub.bin
DIAGNOSTICS     = $(BOARD_ROOT)/diagnostics
DIAGNOSTICS_BIN = $(BOARD_ROOT)/diagnostics.bin

IMAGE_NAME=normal-$(BOARD_TYPE)

.PHONY: all
all: $(DIR)/$(IMAGE_NAME).bin

#
# Rules for node 0 boot stub
#
$(DIR)/$(IMAGE_NAME).bin: $(IMAGE_NAME).bin
	cp $(IMAGE_NAME).bin $(DIR)/$(IMAGE_NAME).bin

# Initial stage 0 chainloader
$(STAGE0_BIN): $(CHAINLOADER_BIN)
	if [ `stat -c %s $^` -gt 196608 ]; then echo "ERROR: $^ image must be 192KB or less";exit 1;fi
	cp $(CHAINLOADER_BIN) $(STAGE0_BIN)

# BDK image
$(STAGE1_BIN): $(BOOT_STUB_BIN)
	cp $(BOOT_STUB_BIN) $(STAGE1_BIN)

# Diagnostics image
$(STAGE2_BIN): $(DIAGNOSTICS_BIN)
	cp $(DIAGNOSTICS_BIN) $(STAGE2_BIN)

$(FATFS_IMG): $(STAGE1_BIN) $(STAGE2_BIN) $(BOARD_ROOT)/lua/*
	# Create empty 3.5MB image file
	dd if=/dev/zero of=$(FATFS_IMG) bs=1k count=3584 2>/dev/null

	# Create FAT filesystem in image file
	$(BDK_ROOT)/bin/fatfs-tool -q -i $(FATFS_IMG) mkfs

	# Copy stage 1 & 2 images into FAT filesystem
	$(BDK_ROOT)/bin/fatfs-tool -q -i $(FATFS_IMG) cp $(STAGE1_BIN) /
	$(BDK_ROOT)/bin/fatfs-tool -q -i $(FATFS_IMG) cp $(STAGE2_BIN) /

	# Add all the Lua files to the FAT fs
	$(BDK_ROOT)/bin/fatfs-tool -q -i $(FATFS_IMG) mkdir /lua
	$(BDK_ROOT)/bin/fatfs-tool -q -i $(FATFS_IMG) cp $(BOARD_ROOT)/lua/*.lua /lua

	$(BDK_ROOT)/bin/fatfs-tool -q -i $(FATFS_IMG) cp $(BOARD_ROOT)/default.cfg /
	@cp $(BOARD_ROOT)/default.cfg ./safe-mode.cfg
	$(BDK_ROOT)/bin/fatfs-tool -q -i $(FATFS_IMG) cp ./safe-mode.cfg /
	@rm ./safe-mode.cfg


$(IMAGE_NAME).bin: $(STAGE0_BIN) $(STAGE1_BIN) $(STAGE2_BIN) $(FATFS_IMG)
	#
	# 1) 0x000000: 64KB unused by Thunder
	cat ptable-16MB-0x080000-0x300000-2.5M.img /dev/zero | head -q -c 65536 > $(IMAGE_NAME).bin
	# 2) 0x010000: 64KB of CVM_CLIB header
	echo -n CVM_CLIB | cat - /dev/zero | head -q -c 65536 >> $(IMAGE_NAME).bin
	# 3) 0x020000: 192KB of chainloader image (non-trusted)
	cat $(STAGE0_BIN) /dev/zero | head -q -c 196608 >> $(IMAGE_NAME).bin
	# 4) 0x050000: 192KB of chainloader image (trusted)
	cat $(STAGE0_BIN) /dev/zero | head -q -c 196608 >> $(IMAGE_NAME).bin
	# 5) 0x080000: 3.5MB FAT filesystem
	cat $(FATFS_IMG) /dev/zero | head -q -c 3670016 >> $(IMAGE_NAME).bin
	# You need to install ATF starting at 0x400000

$(CHAINLOADER): $(BOARD_ROOT)/chainloader.o $(BOARD_ROOT)/boot-common.o $(BOARD_OBJS) $(BDK_ROOT)/libbdk/libbdk.a
$(DIAGNOSTICS): $(BOARD_ROOT)/diagnostics.o $(BOARD_OBJS) $(BDK_ROOT)/libbdk/libbdk.a
$(BOOT_STUB):   $(BOARD_ROOT)/boot-stub.o   $(BOARD_ROOT)/boot-common.o $(BOARD_OBJS) $(BDK_ROOT)/libbdk/libbdk.a

$(COMMON_OBJS): $(BOARD_ROOT)/%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(BOARD_ROOT)/*.o $(BOARD_ROOT)/*.map $(BOARD_ROOT)/*.bin $(CHAINLOADER) $(DIAGNOSTICS) $(BOOT_STUB) $(IMAGE_NAME).bin $(DIR)/$(IMAGE_NAME).bin
