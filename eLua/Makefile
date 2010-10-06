#LUA_TARGET=lua
LUA_TARGET=lualong
SCONS_OPTIONS=target=$(LUA_TARGET) board=OCTEON-EVB optram=false romfs=verbatim #boot=luarpc

default: luac.cross.elf luarpc
	scons $(SCONS_OPTIONS) -s

clean:
	scons $(SCONS_OPTIONS) -s -c

run:
	oct-sim elua_$(LUA_TARGET)_cn6xxx.elf -uart0=2020 -quiet

tftp: default
	mipsisa64-octeon-elf-strip -o /tftpboot/elua elua_$(LUA_TARGET)_cn6xxx.elf

luac.cross.elf:
	scons -s -f cross-lua.py
luarpc:
	scons -s -f rpc-lua.py
