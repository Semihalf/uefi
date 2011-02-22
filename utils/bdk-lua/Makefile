#
# Setup the compile flags
#
CPPFLAGS = -I $(BDK_ROOT)/libbdk -I $(BDK_ROOT)/liblua -DLUA_ROOT='"./"' -DLUA_USE_LINUX
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
src := $(foreach d,$(dirs),$(BDK_ROOT)/$(d)/*.[cS])
src := $(wildcard $(src))

bdk-lua: $(src)
	$(CC) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@ $^

.PHONY: clean
clean:
	rm -f bdk-lua
