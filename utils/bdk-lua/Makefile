#
# Setup the compile flags
#
CPPFLAGS = -I $(BDK_ROOT) -I $(BDK_ROOT)/liblua -I $(BDK_ROOT)/libbdk -DLUA_ROOT='"./"' -DLUA_USE_LINUX
CFLAGS = -Wall -Wextra -Wno-unused-parameter -O3 -g -std=gnu99 -march=i686 -m32
ASFLAGS = $(CFLAGS)
LDFLAGS = -lreadline -lm -ldl

#
# These are the directories where source files are found
#
dirs = liblua
dirs += utils/bdk-lua

#
# Create a list of all source files
#
src := $(foreach d,$(dirs),$(BDK_ROOT)/$(d)/*.[c])
src := $(wildcard $(src))
src += $(BDK_ROOT)/libbdk-arch/bdk-csr.c
src += $(BDK_ROOT)/libbdk-arch/bdk-csrs.c
src += $(BDK_ROOT)/libbdk-arch/bdk-warn.c

bdk-lua: $(src) octeon-remote-mips-asm.o
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $^

octeon-remote-mips-asm.o: mips-octeon_debug_handler.bin mips-octeon2_debug_handler.bin mips-octeon_profile_handler.bin
	$(CC) $(CFLAGS) -c -o $@ octeon-remote-mips-asm.S

mips-%.o: mips-%.S
	mips64-octeon-linux-gnu-gcc -W -Wall -o $@ -c $<
mips-%.bin: mips-%.o
	mips64-octeon-linux-gnu-objcopy -j .text -O binary $< $@

.PHONY: clean
clean:
	rm -f bdk-lua *.o *.bin

