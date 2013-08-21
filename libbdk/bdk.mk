ifndef BDK_ROOT
$(error Define BDK_ROOT in the environment)
endif

SHELL=/bin/bash

#
# Optional compile time flags for the BDK
#
#BDK_EXTRA_CPPFLAGS += -DBDK_SHOW_BOOT_BANNERS=0
#BDK_EXTRA_CPPFLAGS += -DBDK_DISABLE_QLM_JTAG=1

#
# Setup the compiler for the BDK libraries
#
CROSS=mipsisa64-octeon-elf-
CC=$(CROSS)gcc
AR=$(CROSS)ar
AS=$(CROSS)as
LD=$(CROSS)ld
RANLIB=$(CROSS)ranlib
STRIP=$(CROSS)strip
SIM=cn70xx
ifeq ($(shell uname -m),x86_64)
    SIMULATOR=${OCTEON_ROOT}/host/bin/$(SIM)-simulator64
else
    SIMULATOR=${OCTEON_ROOT}/host/bin/$(SIM)-simulator
endif

#
# Setup the compile flags
#
CPPFLAGS = $(BDK_EXTRA_CPPFLAGS)
CPPFLAGS += -I $(BDK_ROOT)/libbdk -I $(BDK_ROOT)/liblua -I $(BDK_ROOT)/libc/mipsisa64-octeon-elf/include
CFLAGS = -Wall -Wextra -Wno-unused-parameter -Os -g -march=octeon2 -std=gnu99 -fno-asynchronous-unwind-tables
ASFLAGS = $(CFLAGS)

LDFLAGS  = -nostdlib -nostartfiles
LDFLAGS += -L $(BDK_ROOT)/libbdk $(BDK_ROOT)/libbdk-os/bdk-start.o
LDFLAGS += -Wl,-T -Wl,bdk.ld -Wl,-Map -Wl,$@.map
LDLIBS = -lbdk -lgcc

INIT_SECTIONS=.init
DATA_SECTIONS=.data .sdata .sbss .bss .eh_frame
TEXT_SECTIONS=.text .rodata
INIT_SECTIONS := $(foreach s,$(INIT_SECTIONS), --only-section=$(s))
DATA_SECTIONS := $(foreach s,$(DATA_SECTIONS), --only-section=$(s))
TEXT_SECTIONS := $(foreach s,$(TEXT_SECTIONS), --only-section=$(s))
IMAGE_END=`mipsisa64-octeon-elf-objdump -t $^ | grep " _end$$" | sed "s/^8\([0-9a-f]*\).*/print 0x\1/g" | python`
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
	mipsisa64-octeon-elf-objcopy $^ $(INIT_SECTIONS) -O binary $@-init.tmp
	mipsisa64-octeon-elf-objcopy $^ $(TEXT_SECTIONS) $(DATA_SECTIONS) -O binary $@-text-data.tmp
	cat $@-init.tmp $@-text-data.tmp /dev/zero | dd of=$@ bs=1 count=$(IMAGE_END) &> /dev/null
	rm $@-init.tmp $@-text-data.tmp
	$(BDK_ROOT)/bin/bdk-update-romfs $@ $@



