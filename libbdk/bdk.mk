ifndef BDK_ROOT
    $(error Define BDK_ROOT in the environment)
endif
ifdef BDK_CLANG_ROOT
    USE_LLVM=1
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
ifdef USE_LLVM
    LLVM_TARGET=-target aarch64-cavium-none-elf -march=armv8.1a+crypto
    CC=$(BDK_CLANG_ROOT)/clang $(LLVM_TARGET) -ccc-gcc-name $(LIBC_DIR)-gcc
    AR=$(BDK_CLANG_ROOT)/llvm-ar
    AS=$(BDK_CLANG_ROOT)/llvm-as $(LLVM_TARGET)
    RANLIB=$(BDK_CLANG_ROOT)/llvm-ranlib
    OBJCOPY=$(LIBC_DIR)-objcopy
else
    CC=$(LIBC_DIR)-gcc
    AR=$(LIBC_DIR)-ar
    AS=$(LIBC_DIR)-as
    RANLIB=$(LIBC_DIR)-ranlib
    OBJCOPY=$(LIBC_DIR)-objcopy
endif

#
# Setup the compile flags
#
CPPFLAGS  = $(BDK_EXTRA_CPPFLAGS)
CPPFLAGS += -I $(BDK_ROOT)/libbdk
CPPFLAGS += -I $(BDK_ROOT)/liblua
CPPFLAGS += -I $(BDK_ROOT)/libc/${LIBC_DIR}/include
CPPFLAGS += -I $(BDK_ROOT)/libfdt

CFLAGS  = -Wall
CFLAGS += -Wextra
CFLAGS += -Wno-unused-parameter
CFLAGS += -Winline
CFLAGS += -Winvalid-pch
ifndef USE_LLVM
    GCC_GTEQ_5 := $(shell expr `${CC} -dumpversion | sed -e 's/\.\([0-9][0-9]\)/\1/g' -e 's/\.\([0-9]\)/0\1/g' -e 's/^[0-9]\{3,4\}$$/&00/'` \>= 50000)
    ifeq "$(GCC_GTEQ_5)" "1"
	CFLAGS += -mcpu=thunderx+lse
    else
	CFLAGS += -mcpu=thunderx
    endif
endif
CFLAGS += -Os -g
CFLAGS += -std=gnu11
CFLAGS += -fno-asynchronous-unwind-tables
CFLAGS += -ffunction-sections
CFLAGS += -fshort-wchar

ASFLAGS = $(CFLAGS)

LDFLAGS  = -nostdlib
LDFLAGS += -nostartfiles
LDFLAGS += -Wl,-T
LDFLAGS += -Wl,bdk.ld
LDFLAGS += -Wl,-Map
LDFLAGS += -Wl,$@.map
LDFLAGS += -Wl,--gc-sections
LDFLAGS += -Wl,--defsym=BDK_LINK_ADDRESS=$(BDK_LINK_ADDRESS)
LDFLAGS += -L $(BDK_ROOT)/libbdk
LDFLAGS += $(BDK_ROOT)/libbdk-os/bdk-start.o

LDLIBS  = -lbdk
ifndef USE_LLVM
    LDLIBS += -lgcc
endif

# This leaves off the bits [63:40] as these contain the node ID, which we don't want
IMAGE_END=`$(LIBC_DIR)-objdump -t $^ | grep " _end$$" | sed "s/^00000[0-9]\([0-9a-f]*\).*/print 0x\1/g" | python`

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
	$(OBJCOPY) $^ -O binary $@.tmp
	cat $@.tmp /dev/zero | dd of=$@ bs=1 count=$(IMAGE_END) &> /dev/null
	rm $@.tmp
	$(BDK_ROOT)/bin/bdk-update-romfs $@ $@



