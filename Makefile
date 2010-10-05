CROSS=mipsisa64-octeon-elf-
CC=$(CROSS)gcc
AR=$(CROSS)ar
LD=$(CROSS)ld
RANLIB=$(CROSS)ranlib

CPPFLAGS = -I $(BDK_ROOT)
CFLAGS = -W -Wall -Wno-unused-parameter -O3 -g

dirs = libbdk-arch libbdk-hal

src := $(foreach d,$(dirs),$(BDK_ROOT)/$(d)/*.[cSs])
src := $(wildcard $(src))
objs = $(src:%.c=%.o)
deps = $(src:%.c=%.d)

$(BDK_ROOT)/libbdk.a: $(BDK_ROOT)/bdk.pch $(BDK_ROOT)/libbdk.a($(objs))

deps += $(BDK_ROOT)/bdk.d
$(BDK_ROOT)/bdk.pch: $(BDK_ROOT)/bdk.h
	$(CC) -o $@ $(BDK_ROOT)/bdk.h
$(BDK_ROOT)/bdk.d: $(BDK_ROOT)/bdk.h
	$(CC) -M $(CPPFLAGS) $< > $@
	sed -i "s,^bdk.o,$(basename $@).pch,g" $@

%.pch: %.d
%.o: %.d $(BDK_ROOT)/bdk.pch
%.d: %.c
	$(CC) -M $(CPPFLAGS) $< > $@
	sed -i "s,^\(.*[.]o\),$(basename $@).o,g" $@
-include $(deps)

clean:
	rm -f $(BDK_ROOT)/libbdk.a $(objs)
mrproper: clean
	rm -f $(deps)

