ifndef BDK_ROOT
$(error Define BDK_ROOT in the environment)
endif

SHELL=/bin/bash

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

#
# Setup the compile flags
#
CPPFLAGS = -I $(BDK_ROOT)/libbdk -I $(BDK_ROOT)/liblua -I $(BDK_ROOT)/libc/mipsisa64-octeon-elf/include
CFLAGS = -Wall -Wextra -Wno-unused-parameter -O3 -g -march=octeon2 -std=gnu99 -fno-asynchronous-unwind-tables
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
TEXT_START=`mipsisa64-octeon-elf-objdump -t $^ | grep _ftext | sed "s/^e\([0-9a-f]*\).*/print 0x\1/g" | python`
#
# This is needed to generate the depends files
#
%.d: %.c
	$(CC) -M $(CPPFLAGS) $< > $@
	sed -i "s,^\(.*[.]o\),$(basename $@).o,g" $@

#
# Convert an ELF file into a binary
#
%.bin: %
	mipsisa64-octeon-elf-objcopy $^ $(INIT_SECTIONS) -O binary init.tmp
	mipsisa64-octeon-elf-objcopy $^ $(DATA_SECTIONS) -O binary data.tmp
	mipsisa64-octeon-elf-objcopy $^ $(TEXT_SECTIONS) -O binary text.tmp
	cat init.tmp data.tmp /dev/zero | dd of="init+data.tmp" bs=1 count=$(TEXT_START) &> /dev/null
	cat init+data.tmp text.tmp > $@
	rm init.tmp data.tmp init+data.tmp text.tmp
	$(OCTEON_ROOT)/bootloader/u-boot/tools/update_octeon_header $@ generic --text_base=0xffffffffE0000000



