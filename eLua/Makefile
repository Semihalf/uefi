SCONS_OPTIONS=target=lualong board=OCTEON-EVB optram=false romfs=compile

default: luac.cross
	scons $(SCONS_OPTIONS) -s

clean:
	scons $(SCONS_OPTIONS) -s -c

run:
	oct-sim elua_lualong_cn6xxx.elf -uart0=2020 -quiet

luac.cross:
	scons -f cross-lua.py
