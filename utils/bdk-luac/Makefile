#
# Setup the compile flags
#
CPPFLAGS = -I $(BDK_ROOT) -I $(BDK_ROOT)/liblua -I $(BDK_ROOT)/libbdk -D_GNU_SOURCE -DBDK_BUILD_HOST
CFLAGS = -Wall -Wextra -Wno-unused-parameter -O3 -g -std=gnu99
ASFLAGS = $(CFLAGS)
LDFLAGS = -lm -ldl

# This is needed to avoid using tmpnam, which creates a warning
CPPFLAGS += -DLUA_USE_MKSTEMP

# Building for x86
#    1) Build for 32bit
#    2) Link static
CPPFLAGS_x86 =
CFLAGS_x86 = -march=i686 -m32
ASFLAGS_x86 = -march=i686 -m32
LDFLAGS_x86 = -static
CC_x86 = gcc
STRIP_x86 = strip

# Building for THUNDERX
CPPFLAGS_thunder =
CFLAGS_thunder =
ASFLAGS_thunder =
LDFLAGS_thunder = -static
CC_thunder = aarch64-thunder-linux-gnu-gcc
STRIP_thunder = aarch64-thunder-linux-gnu-strip

#
# These are the directories where source files are found
#
dirs = liblua
dirs += utils/bdk-luac

#
# Create a list of all source files
#
src := $(foreach d,$(dirs),$(BDK_ROOT)/$(d)/*.[c])
src := $(wildcard $(src))
src += $(BDK_ROOT)/libbdk-os/bdk-readline.c
src += $(BDK_ROOT)/libbdk-lua/readline.c

.DEFAULT: all
all: bdk-luac-x86 bdk-luac-thunder

define build_rule
obj-$(2)/$$(notdir $(1:%.c=%.o)): $(1) | obj-$(2)
	$$(CC_$(2)) $(CPPFLAGS) $$(CPPFLAGS_$(2)) $$(CFLAGS) $$(CFLAGS_$(2)) -o $$@ -c $$^
endef

define build_arch
obj_$(1) := $$(foreach s,$$(src),obj-$(1)/$$(notdir $$(s:%.c=%.o)))
obj-$(1):
	mkdir obj-$(1)
bdk-luac-$(1): $$(obj_$(1))
	$$(CC_$(arch)) $$(CFLAGS_$(1)) -o $$@ $$^ $$(LDFLAGS) $$(LDFLAGS_$(1))
	$$(STRIP_$(arch)) $$@
endef

$(foreach arch,x86 thunder,\
	$(eval $(call build_arch,$(arch))) \
	$(foreach s,$(src), \
		$(eval $(call build_rule,$(s),$(arch))) \
	) \
)

.PHONY: clean
clean:
	rm -rf bdk-luac-* obj-*

