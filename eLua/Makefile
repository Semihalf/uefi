#LUA_TARGET=lua
LUA_TARGET=lualong
SCONS_OPTIONS=target=$(LUA_TARGET) board=OCTEON-EVB optram=false romfs=compile

default: luac.cross
	scons $(SCONS_OPTIONS) -s

clean:
	scons $(SCONS_OPTIONS) -s -c

run:
	oct-sim elua_$(LUA_TARGET)_cn6xxx.elf -uart0=2020 -quiet

luac.cross:
	scons -f cross-lua.py
