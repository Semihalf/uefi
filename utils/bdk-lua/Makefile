#
# Setup the compile flags
#
CPPFLAGS = -I $(BDK_ROOT) -I $(BDK_ROOT)/liblua -I $(BDK_ROOT)/libbdk -D_GNU_SOURCE -DBDK_BUILD_HOST
CFLAGS = -Wall -Wextra -Wno-unused-parameter -O3 -g -std=gnu99
ASFLAGS = $(CFLAGS)
LDFLAGS = -lm -ldl

# These are needed for luasocket to compile cleanly
CPPFLAGS += -DLUA_COMPAT_MODULE -DluaL_typerror=luaL_typeerror -DluaL_putchar=luaL_addchar

# Building for x86
#    1) Build for 32bit
#    2) Link static
CPPFLAGS_x86 =
CFLAGS_x86 = -march=i686 -m32
ASFLAGS_x86 = -march=i686 -m32
LDFLAGS_x86 = -static
CC_x86 = gcc

# Building for PPC
#    1) Link static
PPC_ROOT=/home/creese/work/debian_ppc_lenny
CPPFLAGS_ppc =
CFLAGS_ppc =
ASFLAGS_ppc =
LDFLAGS_ppc = -static
CC_ppc = ssh bdk-build-ppc "cd `pwd` && gcc"

# Building for Octeon
CPPFLAGS_octeon =
CFLAGS_octeon = -march=octeon2
ASFLAGS_octeon = -march=octeon2
LDFLAGS_octeon =
CC_octeon = mips64-octeon-linux-gnu-gcc
arch=$(patsubst %.o,%,$(lastword $(subst -, ,$@)))

#
# These are the directories where source files are found
#
dirs = liblua
dirs += utils/bdk-lua
dirs += utils/bdk-lua/libluasocket

#
# Create a list of all source files
#
src := $(foreach d,$(dirs),$(BDK_ROOT)/$(d)/*.[c])
src := $(wildcard $(src))
src += $(BDK_ROOT)/libbdk-arch/bdk-csr.c
src += $(BDK_ROOT)/libbdk-arch/bdk-csrs.c
src += $(BDK_ROOT)/libbdk-arch/bdk-warn.c
src += $(BDK_ROOT)/libbdk-os/bdk-readline.c
src += $(BDK_ROOT)/libbdk-lua/bdk-lua.c
src += $(BDK_ROOT)/libbdk-lua/octeon-model.c
src += $(BDK_ROOT)/libbdk-lua/octeon-csr.c
src += $(BDK_ROOT)/libbdk-lua/octeon-constants.c
src += $(BDK_ROOT)/libbdk-lua/lbitlib64.c
src += $(BDK_ROOT)/libbdk-lua/readline.c

bdk-lua-%: $(src) octeon-remote-mips-asm-%.o
	$(CC_$(arch)) $(CPPFLAGS) $(CPPFLAGS_$(arch)) $(CFLAGS) $(CFLAGS_$(arch)) -o $@ $^ $(LDFLAGS) $(LDFLAGS_$(arch))

octeon-remote-mips-asm-%.o: mips-octeon2_debug_handler.bin
	$(CC_$(arch)) $(CFLAGS) $(CFLAGS_$(arch)) -c -o $@ octeon-remote-mips-asm.S

mips-%.o: mips-%.S
	mips64-octeon-linux-gnu-gcc -W -Wall -o $@ -c $<
mips-%.bin: mips-%.o
	mips64-octeon-linux-gnu-objcopy -j .text -O binary $< $@

.DEFAULT: all
all: bdk-lua-x86 bdk-lua-octeon

.PHONY: ppc
ppc: bdk-lua-ppc

.PHONY: clean
clean:
	rm -f bdk-lua-* *.o *.bin

.PHONY: suid
suid:
	sudo chown root bdk-lua-x86
	sudo chmod +s bdk-lua-x86

