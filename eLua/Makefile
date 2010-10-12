#LUA_TARGET=lua
LUA_TARGET=lualong
SCONS_OPTIONS=target=$(LUA_TARGET) board=OCTEON-EVB optram=false romfs=verbatim #boot=luarpc

INIT_SECTIONS=.init
DATA_SECTIONS=.data .sdata .sbss .bss
TEXT_SECTIONS=.text .rodata .eh_frame

INIT_SECTIONS := $(foreach s,$(INIT_SECTIONS), --only-section=$(s))
DATA_SECTIONS := $(foreach s,$(DATA_SECTIONS), --only-section=$(s))
TEXT_SECTIONS := $(foreach s,$(TEXT_SECTIONS), --only-section=$(s))

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
	scons $(SCONS_OPTIONS) -s

tftp: $(TARGET) $(TARGET:%.elf=%.bin)
	mipsisa64-octeon-elf-strip -o /tftpboot/elua $(TARGET)
	cp $(TARGET:%.elf=%.bin) /tftpboot/elua.bin

$(TARGET:%.elf=%.bin): $(TARGET)
	mipsisa64-octeon-elf-objcopy $^ $(INIT_SECTIONS) -O binary init.tmp
	mipsisa64-octeon-elf-objcopy $^ $(DATA_SECTIONS) -O binary data.tmp
	mipsisa64-octeon-elf-objcopy $^ $(TEXT_SECTIONS) -O binary text.tmp
	cat init.tmp data.tmp /dev/zero | dd of="init+data.tmp" bs=4096 count=3 &> /dev/null
	cat init+data.tmp text.tmp > $@
	rm init.tmp data.tmp init+data.tmp text.tmp

luac.cross.elf:
	scons -s -f cross-lua.py
luarpc:
	scons -s -f rpc-lua.py
