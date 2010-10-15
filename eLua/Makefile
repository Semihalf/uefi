include $(BDK_ROOT)/libbdk/bdk.mk

#LUA_TARGET=lua
LUA_TARGET=lualong
SCONS_OPTIONS=target=$(LUA_TARGET) board=OCTEON-EVB optram=false romfs=verbatim #boot=luarpc

TARGET=elua_$(LUA_TARGET)_cn6xxx.elf

default: luac.cross.elf luarpc $(TARGET)

clean:
	scons $(SCONS_OPTIONS) -s -c

run: $(TARGET:%.elf=%.bin)
	cn63xx-simulator64 -ld0x1fc00000:$(TARGET) -ld0x1fc00000:$(TARGET:%.elf=%.bin) -ld0:0x280 -ld0x30000000:0x10000000 -modes=fastboot -uart0=2020 -quiet

run-ub: $(TARGET:%.elf=%.bin)
	oct-sim u-boot-env -ld0x100000:$(TARGET) -ld0x400000:$(TARGET:%.elf=%.bin) -ld0x30000000:0x10000000 -uart0=2020 -envfile=u-boot-env -memsize=4 -quiet

.PHONY: $(TARGET)
$(TARGET):
	CFLAGS="$(CPPFLAGS) $(CFLAGS)" LDFLAGS="$(LDFLAGS)" scons $(SCONS_OPTIONS) -s

tftp: $(TARGET) $(TARGET:%.elf=%.bin)
	mipsisa64-octeon-elf-strip -o /tftpboot/elua $(TARGET)
	cp $(TARGET:%.elf=%.bin) /tftpboot/elua.bin

luac.cross.elf:
	scons -s -f cross-lua.py
luarpc:
	scons -s -f rpc-lua.py
