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
CPPFLAGS = -I $(BDK_ROOT)
CFLAGS = -W -Wall -Wno-unused-parameter -O3 -g -ffunction-sections -fdata-sections

#
# These are the directories where source files are found
#
dirs  = libbdk-arch
dirs += libbdk-hal

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
$(BDK_ROOT)/libbdk.a: $(BDK_ROOT)/bdk.pch $(objs)
	$(AR) qc $@ $(objs)

#
# These are needed to make bdk.pch
#
deps += $(BDK_ROOT)/bdk.d
$(BDK_ROOT)/bdk.pch: $(BDK_ROOT)/bdk.h
	$(CC) -o $@ $(BDK_ROOT)/bdk.h
$(BDK_ROOT)/bdk.d: $(BDK_ROOT)/bdk.h
	$(CC) -M $(CPPFLAGS) $< > $@
	sed -i "s,^bdk.o,$(basename $@).pch,g" $@

#
# These are needed to generate the depends files
#
%.pch: %.d
%.o: %.d $(BDK_ROOT)/bdk.pch
%.d: %.c
	$(CC) -M $(CPPFLAGS) $< > $@
	sed -i "s,^\(.*[.]o\),$(basename $@).o,g" $@

#
# Include all the depends files
#
-include $(deps)

#
# Clean targets
#
clean:
	rm -f $(BDK_ROOT)/libbdk.a $(objs)
mrproper: clean
	rm -f $(deps)

