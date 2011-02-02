include $(BDK_ROOT)/libbdk/bdk.mk

crypto.bin: crypto
crypto: crypto.o $(BDK_ROOT)/libbdk/libbdk.a

clean:
	rm -f *.o crypto crypto.bin crypto.map

tftp: crypto.bin
	cp crypto.bin /tftpboot/

run: crypto.bin
	cn68xx-simulator64 -ld0x1fc00000:crypto -ld0x1fc00000:crypto.bin -ld0:0x400000 -modes=fastboot,pass1 -quiet -numcores=7

