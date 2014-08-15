#
# Setup the compile flags
#
CPPFLAGS = -I $(BDK_ROOT) -I $(BDK_ROOT)/liblua -I $(BDK_ROOT)/libbdk -D_GNU_SOURCE -DBDK_BUILD_HOST
CFLAGS = -Wall -Wextra -Wno-unused-parameter -O3 -g -std=gnu99
ASFLAGS = $(CFLAGS)
LDFLAGS = -lm -ldl

# This is needed to avoid using tmpnam, which creates a warning
CPPFLAGS += -DLUA_USE_MKSTEMP

# These are needed for luasocket to compile cleanly
CPPFLAGS += -DLUA_COMPAT_MODULE -DluaL_putchar=luaL_addchar

# Building for x86
#    1) Build for 32bit
#    2) Link static
CPPFLAGS_x86 =
CFLAGS_x86 = -march=i686 -m32
ASFLAGS_x86 = -march=i686 -m32
LDFLAGS_x86 = -static
CC_x86 = gcc
STRIP_x86 = strip

# Building for PPC
#    1) Link static
CPPFLAGS_ppc =
CFLAGS_ppc =
ASFLAGS_ppc =
LDFLAGS_ppc = -static
CC_ppc = sshany -m bdk-build-ppc1 -m bdk-build-ppc2 -- "cd `pwd` && gcc"
STRIP_ppc = sshany -m bdk-build-ppc1 -m bdk-build-ppc2 -- "cd `pwd` && strip"

# Building for Thunder
CPPFLAGS_thunder =
CFLAGS_thunder = -march=thunderx
ASFLAGS_thunder = -march=thunderx
LDFLAGS_thunder =
CC_thunder = aarch64-thunderx-linux-gnu-gcc
STRIP_thunder = aarch64-thunderx-linux-gnu-strip

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
src += $(BDK_ROOT)/libbdk-arch/bdk-warn.c
src += $(BDK_ROOT)/libbdk-os/bdk-readline.c
src += $(BDK_ROOT)/libbdk-lua/bdk-lua.c
src += $(BDK_ROOT)/libbdk-lua/cavium-mmc.c
src += $(BDK_ROOT)/libbdk-lua/cavium-model.c
src += $(BDK_ROOT)/libbdk-lua/cavium-constants.c
src += $(BDK_ROOT)/libbdk-lua/lbitlib64.c
src += $(BDK_ROOT)/libbdk-lua/readline.c
src += $(BDK_ROOT)/libbdk-lua/rpc-support.c

.DEFAULT: all
all: bdk-lua-x86 bdk-lua-thunder

.PHONY: ppc
ppc: bdk-lua-ppc


define build_rule
obj-$(2)/$$(notdir $(1:%.c=%.o)): $(1) | obj-$(2)
	$$(CC_$(2)) $(CPPFLAGS) $$(CPPFLAGS_$(2)) $$(CFLAGS) $$(CFLAGS_$(2)) -o $$@ -c $$^
endef

define build_arch
obj_$(1) := $$(foreach s,$$(src),obj-$(1)/$$(notdir $$(s:%.c=%.o)))
obj_$(1) += obj-$(1)/octeon-remote-mips-asm.o
obj-$(1):
	mkdir obj-$(1)
obj-$(1)/octeon-remote-mips-asm.o: mips-octeon3_debug_handler.bin | obj-$(1)
	$$(CC_$(1)) $$(CFLAGS) $$(CFLAGS_$(1)) -c -o $$@ octeon-remote-mips-asm.S
bdk-lua-$(1): $$(obj_$(1))
	$$(CC_$(arch)) $$(CFLAGS_$(1)) -o $$@ $$^ $$(LDFLAGS) $$(LDFLAGS_$(1))
	$$(STRIP_$(arch)) $$@
endef

$(foreach arch,x86 ppc thunder,\
	$(eval $(call build_arch,$(arch))) \
	$(foreach s,$(src), \
		$(eval $(call build_rule,$(s),$(arch))) \
	) \
)

mips-%.o: mips-%.S
	aarch64-thunderx-linux-gnu-gcc -W -Wall -o $@ -c $<
mips-%.bin: mips-%.o
	aarch64-thunderx-linux-gnu-objcopy -j .text -O binary $< $@

.PHONY: clean
clean:
	rm -rf bdk-lua-* *.o *.bin obj-*

.PHONY: suid
suid:
	sudo chown root bdk-lua-x86
	sudo chmod +s bdk-lua-x86

