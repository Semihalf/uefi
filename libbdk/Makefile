include bdk.mk

#
# These are the directories where source files are found
#
dirs  = libbdk-arch
dirs += libbdk-hal
dirs += libbdk-hal/if
dirs += libbdk-hal/qlm
dirs += libbdk-os
dirs += libbdk-dram
dirs += liblua
dirs += libbdk-lua

#
# Create a list of all source files
#
src := $(foreach d,$(dirs),$(BDK_ROOT)/$(d)/*.[cS])
src := $(wildcard $(src))

#
# Create a list of all objects and depends files
#
objs = $(addsuffix .o, $(basename $(src)))
deps = $(addsuffix .d, $(basename $(src)))

#
# The library depends on the precompiled header and all the object files
#
.DEFAULT: $(BDK_ROOT)/libbdk/libbdk.a
$(BDK_ROOT)/libbdk/libbdk.a: $(BDK_ROOT)/libbdk/bdk.pch $(objs) bdk-functions.o $(BDK_ROOT)/libc/${LIBC_DIR}/lib/libc.a
	rm -f $@
	$(AR) qc $@ $(objs) bdk-functions.o
	rm -rf tmp
	mkdir tmp
	cd tmp && $(AR) x $(BDK_ROOT)/libc/${LIBC_DIR}/lib/libc.a
	cd tmp && $(AR) x $(BDK_ROOT)/libc/${LIBC_DIR}/lib/libg.a
	cd tmp && $(AR) x $(BDK_ROOT)/libc/${LIBC_DIR}/lib/libm.a
	$(AR) r $@ tmp/*
	rm -rf tmp

bdk-functions.c: ./create_function_table.py $(objs)
	./create_function_table.py $@ $(objs)

#
# These are needed to make bdk.pch
# The -M creates the dependencies to stdout
# The -MP creates fake target for .h files so make won't complain on include changes
# The -MT changes the target to match our object file name
#
deps += $(BDK_ROOT)/libbdk/bdk.d
$(BDK_ROOT)/libbdk/bdk.pch: $(BDK_ROOT)/libbdk/bdk.h
	$(CC) -o $@ $(BDK_ROOT)/libbdk/bdk.h
$(BDK_ROOT)/libbdk/bdk.d: $(BDK_ROOT)/libbdk/bdk.h
	$(CC) -M -MP -MT $(basename $@).pch $(CPPFLAGS) $< > $@

#
# Lua to C wrapper functions created by SWIG
#
%_wrap.c: %.i
	swig -Wall -nodefaultctor -nodefaultdtor -lua -o $@ $^

#
# These are needed to generate the depends files
#
%.pch: %.d
%.o: %.d $(BDK_ROOT)/libbdk/bdk.pch

#
# Include all the depends files
#
-include $(deps)

#
# Clean targets
#
clean:
	rm -f $(BDK_ROOT)/libbdk/libbdk.a $(objs) tmp bdk-functions.c bdk-functions.o
distclean: clean
	rm -f $(deps) bdk.pch

UBOOT_PATH=$(OCTEON_ROOT)/bootloader/u-boot
UBOOT_INCLUDE=-I $(UBOOT_PATH)/include -I $(UBOOT_PATH)/arch/mips/include/asm/arch-octeon
$(BDK_ROOT)/libbdk-dram/bdk-dram-config.o $(BDK_ROOT)/libbdk-dram/bdk-dram-config.d: CPPFLAGS += -I $(OCTEON_ROOT)/target/include $(UBOOT_INCLUDE)

$(BDK_ROOT)/libbdk-os/bdk-init.o: CFLAGS+="-fpic"
$(BDK_ROOT)/libbdk-hal/if/bdk-if.o: CFLAGS+="-O3"
$(BDK_ROOT)/libbdk-lua/trafficgen.o: CFLAGS+="-O3"
