CROSS=mipsisa64-octeon-elf

bdk-libc.a: mipsisa64-octeon-elf/lib/libc.a
	rm -rf tmp
	mkdir tmp
	cd tmp && $(CROSS)-ar x ../mipsisa64-octeon-elf/lib/libc.a
	cd tmp && $(CROSS)-ar x ../mipsisa64-octeon-elf/lib/libg.a
	cd tmp && $(CROSS)-ar x ../mipsisa64-octeon-elf/lib/libm.a
	$(CROSS)-ar rc $@ tmp/*
	rm -rf tmp

mipsisa64-octeon-elf/lib/libc.a: build/Makefile
	$(MAKE) -C build
	$(MAKE) -j1 -C build install

build/Makefile:
	rm -rf build
	mkdir build
	cd build && CC=$(CROSS)-gcc ../newlib-1.18.0/newlib/configure --host=$(CROSS) --target=$(CROSS) --disable-multilib --enable-newlib-reent-small --silent --prefix=$(BDK_ROOT)/libc

clean:
	rm -rf build mipsisa64-octeon-elf bdk-libc.a tmp

