include $(BDK_ROOT)/libbdk/bdk.mk

lua.bin: lua
lua: lua.o $(BDK_ROOT)/libbdk/libbdk.a

clean:
	rm -f *.o lua lua.bin

tftp: lua.bin
	cp lua.bin /tftpboot/

run: lua.bin
	cn63xx-simulator64 -ld0x1fc00000:lua -ld0x1fc00000:lua.bin -ld0:0x10000000 -ld0x30000000:0x10000000 -modes=fastboot,pass2 -uart0=2020 -noperf -quiet -serve=2000

