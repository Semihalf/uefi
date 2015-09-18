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

CFG_FILES  = $(BOARD_TYPE)/*.cfg

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

$(IMAGE_NAME).bin: $(STAGE0_BIN) $(STAGE1_BIN) $(STAGE2_BIN) lua-common/*.lua $(BOARD_ROOT)/lua/*.lua $(BOARD_ROOT)/default.cfg
	cp $(BOARD_ROOT)/default.cfg safe-mode.cfg
	$(BDK_ROOT)/bin/bdk-create-fatfs-image -o $@ \
	    -0 $(STAGE0_BIN) -1 $(STAGE1_BIN) -2 $(STAGE2_BIN) \
	    -l "lua-common/*.lua $(BOARD_ROOT)/lua/*.lua" -c "$(BOARD_ROOT)/default.cfg safe-mode.cfg"
	rm safe-mode.cfg

$(CHAINLOADER): $(BOARD_ROOT)/chainloader.o $(BOARD_OBJS) $(BDK_ROOT)/libbdk/libbdk.a
$(DIAGNOSTICS): $(BOARD_ROOT)/diagnostics.o $(BOARD_OBJS) $(BDK_ROOT)/libbdk/libbdk.a
$(BOOT_STUB):   $(BOARD_ROOT)/boot-stub.o $(BOARD_OBJS) $(BDK_ROOT)/libbdk/libbdk.a

$(COMMON_OBJS): $(BOARD_ROOT)/%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f $(BOARD_ROOT)/*.o $(BOARD_ROOT)/*.map $(BOARD_ROOT)/*.bin $(CHAINLOADER) $(DIAGNOSTICS) $(BOOT_STUB) $(IMAGE_NAME).bin $(DIR)/$(IMAGE_NAME).bin
