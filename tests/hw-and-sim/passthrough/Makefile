include $(BDK_ROOT)/libbdk/bdk.mk

passthrough.bin: passthrough
passthrough: passthrough.o $(BDK_ROOT)/libbdk/libbdk.a

clean:
	rm -f *.o passthrough passthrough.bin passthrough.map

tftp: passthrough.bin
	cp passthrough.bin /tftpboot/

run: passthrough.bin
	$(SIMULATOR) -ld0x1fc00000:passthrough -ld0x1fc00000:passthrough.bin -ld0:0x400000 -modes=fastboot,pass1 -quiet -numcores=4

