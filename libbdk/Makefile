include bdk.mk

#
# These are the directories where source files are found
#
dirs  = libbdk-arch
dirs += libbdk-hal
dirs += libbdk-os
dirs += libbdk-dram

#
# Create a list of all source files
#
src := $(foreach d,$(dirs),$(BDK_ROOT)/$(d)/*.[cS])
src := $(wildcard $(src)) $(BDK_ROOT)/libbdk-dram/lib_octeon_shared.c

#
# Create a list of all objects and depends files
#
objs = $(addsuffix .o, $(basename $(src)))
deps = $(addsuffix .d, $(basename $(src)))

#
# The library depends on the precompiled header and all the object files
#
.DEFAULT: $(BDK_ROOT)/libbdk/libbdk.a
$(BDK_ROOT)/libbdk/libbdk.a: $(BDK_ROOT)/libbdk/bdk.pch $(objs) $(BDK_ROOT)/libc/mipsisa64-octeon-elf/lib/libc.a
	rm -f $@
	$(AR) qc $@ $(objs)
	rm -rf tmp
	mkdir tmp
	cd tmp && $(AR) x $(BDK_ROOT)/libc/mipsisa64-octeon-elf/lib/libc.a
	cd tmp && $(AR) x $(BDK_ROOT)/libc/mipsisa64-octeon-elf/lib/libg.a
	cd tmp && $(AR) x $(BDK_ROOT)/libc/mipsisa64-octeon-elf/lib/libm.a
	$(AR) r $@ tmp/*
	rm -rf tmp

#
# These are needed to make bdk.pch
#
deps += $(BDK_ROOT)/libbdk/bdk.d
$(BDK_ROOT)/libbdk/bdk.pch: $(BDK_ROOT)/libbdk/bdk.h
	$(CC) -o $@ $(BDK_ROOT)/libbdk/bdk.h
$(BDK_ROOT)/libbdk/bdk.d: $(BDK_ROOT)/libbdk/bdk.h
	$(CC) -M $(CPPFLAGS) $< > $@
	sed -i "s,^bdk.o,$(basename $@).pch,g" $@

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
	rm -f $(BDK_ROOT)/libbdk/libbdk.a $(objs) tmp
distclean: clean
	rm -f $(deps)

$(BDK_ROOT)/libbdk-dram/lib_octeon_shared.o $(BDK_ROOT)/libbdk-dram/lib_octeon_shared.d: CPPFLAGS = -I $(OCTEON_ROOT)/target/include -I $(OCTEON_ROOT)/bootloader/u-boot/include -Dulong="unsigned long" -Dunix=1
$(BDK_ROOT)/libbdk-dram/lib_octeon_shared.c:
	ln -s $(OCTEON_ROOT)/bootloader/u-boot/lib_mips/lib_octeon_shared.c $@

