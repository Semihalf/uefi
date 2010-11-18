include bdk.mk

#
# These are the directories where source files are found
#
dirs  = libbdk-arch
dirs += libbdk-hal
dirs += libbdk-os
dirs += libbdk-dram
dirs += liblua

#
# Create a list of all source files
#
src := $(foreach d,$(dirs),$(BDK_ROOT)/$(d)/*.[cS])
src := $(wildcard $(src))
ifeq (,$(findstring lib_octeon_shared,$(src)))
    # The wildcard will find it if the link is already there, otherwise
    # we must add it
    src += $(BDK_ROOT)/libbdk-dram/lib_octeon_shared.c
endif


#
# Create a list of all objects and depends files
#
objs = $(addsuffix .o, $(basename $(src)))
deps = $(addsuffix .d, $(basename $(src)))

#
# The library depends on the precompiled header and all the object files
#
.DEFAULT: $(BDK_ROOT)/libbdk/libbdk.a
$(BDK_ROOT)/libbdk/libbdk.a: $(BDK_ROOT)/libbdk/bdk.pch $(objs) bdk-functions.o bdk-fs-rom-files.o $(BDK_ROOT)/libc/mipsisa64-octeon-elf/lib/libc.a
	rm -f $@
	$(AR) qc $@ $(objs) bdk-functions.o bdk-fs-rom-files.o
	rm -rf tmp
	mkdir tmp
	cd tmp && $(AR) x $(BDK_ROOT)/libc/mipsisa64-octeon-elf/lib/libc.a
	cd tmp && $(AR) x $(BDK_ROOT)/libc/mipsisa64-octeon-elf/lib/libg.a
	cd tmp && $(AR) x $(BDK_ROOT)/libc/mipsisa64-octeon-elf/lib/libm.a
	$(AR) r $@ tmp/*
	rm -rf tmp

bdk-functions.c: ./create_function_table.py $(objs)
	./create_function_table.py $@ $(objs)

ROM_FILES=$(wildcard $(BDK_ROOT)/rom/*)
bdk-fs-rom-files.c: ./create_rom_files.py $(ROM_FILES)
	./create_rom_files.py $@ $(BDK_ROOT)/rom/ $(ROM_FILES)

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
	ln -fs $(OCTEON_ROOT)/bootloader/u-boot/lib_mips/lib_octeon_shared.c $@

