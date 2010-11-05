CROSS=mipsisa64-octeon-elf

mipsisa64-octeon-elf/lib/libc.a: build/Makefile
	$(MAKE) -C build
	$(MAKE) -j1 -C build install

build/Makefile:
	rm -rf build
	mkdir build
	cd build && CC=$(CROSS)-gcc CFLAGS="-march=octeon2" ../newlib-1.18.0/newlib/configure --host=$(CROSS) --target=$(CROSS) --disable-multilib --silent --prefix=$(BDK_ROOT)/libc

clean:
	rm -rf build mipsisa64-octeon-elf

