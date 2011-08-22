include $(BDK_ROOT)/libbdk/bdk.mk

bdk-boot.bin: bdk-base.bin $(BDK_ROOT)/rom/*
	$(BDK_ROOT)/bin/bdk-update-romfs $@ $^

bdk-base.bin: bdk-base
bdk-base: bdk-base.o $(BDK_ROOT)/libbdk/libbdk.a

clean:
	rm -f *.o *.map bdk-base bdk-base.bin bdk-boot.bin

tftp: bdk-boot.bin
	cp bdk-boot.bin /tftpboot/

run: bdk-boot.bin
	$(SIMULATOR) -ld0x1fc00000:bdk-base -ld0x1fc00000:bdk-boot.bin -ld0:0x200000 -modes=fastboot,pass2 -uart0=2020 -noperf -quiet -serve=2000

