ifndef BDK_ROOT
$(error Define BDK_ROOT in the environment)
endif

BDK_LINK_ADDRESS?=0x0 # Node 0
#BDK_LINK_ADDRESS?=0x10000000000 # Node 1

SHELL=/bin/bash

#
# Optional compile time flags for the BDK
#
#override BDK_EXTRA_CPPFLAGS += -DBDK_SHOW_BOOT_BANNERS=0

#
# Setup the compiler for the BDK libraries
#
LIBC_DIR=aarch64-thunderx-elf
CROSS=$(LIBC_DIR)-
CC=$(CROSS)gcc
AR=$(CROSS)ar
AS=$(CROSS)as
LD=$(CROSS)ld
RANLIB=$(CROSS)ranlib
STRIP=$(CROSS)strip

#
# Setup the compile flags
#
CPPFLAGS = $(BDK_EXTRA_CPPFLAGS)
CPPFLAGS += -I $(BDK_ROOT)/libbdk -I $(BDK_ROOT)/liblua -I $(BDK_ROOT)/libc/${LIBC_DIR}/include -I $(BDK_ROOT)/libfdt
CFLAGS = -Wall -Wextra -Wno-unused-parameter -Winline -mcpu=thunderx -Os -g -std=gnu99 -fno-asynchronous-unwind-tables
CFLAGS += -ffunction-sections -Winvalid-pch
CFLAGS += -fshort-wchar

ASFLAGS = $(CFLAGS)

LDFLAGS  = -nostdlib -nostartfiles
LDFLAGS += -L $(BDK_ROOT)/libbdk $(BDK_ROOT)/libbdk-os/bdk-start.o
LDFLAGS += -Wl,-T -Wl,bdk.ld -Wl,-Map -Wl,$@.map -Wl,--gc-sections
LDFLAGS += -Wl,--defsym=BDK_LINK_ADDRESS=$(BDK_LINK_ADDRESS)
LDLIBS = -lbdk -lgcc

# This leaves off the bits [63:40] as these contain the node ID, which we don't want
IMAGE_END=`${CROSS}objdump -t $^ | grep " _end$$" | sed "s/^00000[0-9]\([0-9a-f]*\).*/print 0x\1/g" | python`

#
# This is needed to generate the depends files
# The -M creates the dependencies to stdout
# The -MP creates fake target for .h files so make won't complain on include changes
# The -MT changes the target to match our object file name
#
%.d: %.c
	$(CC) -M -MP -MT $(basename $@).o $(CPPFLAGS) $< > $@

#
# Convert an ELF file into a binary
#
%.bin: %
	${CROSS}objcopy $^ -O binary $@.tmp
	cat $@.tmp /dev/zero | dd of=$@ bs=1 count=$(IMAGE_END) &> /dev/null
	rm $@.tmp
	$(BDK_ROOT)/bin/bdk-update-romfs $@ $@



