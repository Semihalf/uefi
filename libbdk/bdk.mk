ifndef BDK_ROOT
$(error Define BDK_ROOT in the environment)
endif

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
CPPFLAGS = -isystem $(BDK_ROOT)/libbdk -isystem $(BDK_ROOT)/libc/mipsisa64-octeon-elf/include
CFLAGS = -W -Wall -Wno-unused-parameter -O3 -g -ffunction-sections -fdata-sections
ASFLAGS = $(CFLAGS)

LDFLAGS  = -nostdlib -nostartfiles --allow-multiple-definition --gc-sections
LDFLAGS += -Wl,--section-start -Wl,.init=0xffffffffBFC00000
LDFLAGS += -Wl,--section-start -Wl,.data=0xffffffffC0000500
LDFLAGS += -Wl,--section-start -Wl,.text=0xffffffffE0044000
LDFLAGS += -L $(BDK_ROOT)/libbdk
LDLIBS = -lbdk -lgcc

INIT_SECTIONS=.init
DATA_SECTIONS=.data .sdata .sbss .bss
TEXT_SECTIONS=.text .rodata .eh_frame
INIT_SECTIONS := $(foreach s,$(INIT_SECTIONS), --only-section=$(s))
DATA_SECTIONS := $(foreach s,$(DATA_SECTIONS), --only-section=$(s))
TEXT_SECTIONS := $(foreach s,$(TEXT_SECTIONS), --only-section=$(s))

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
	cat init.tmp data.tmp /dev/zero | dd of="init+data.tmp" bs=4096 count=68 &> /dev/null
	cat init+data.tmp text.tmp > $@
	rm init.tmp data.tmp init+data.tmp text.tmp



