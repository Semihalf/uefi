CROSS=mipsisa64-octeon-elf

mipsisa64-octeon-elf/lib/libc.a: build/Makefile
	$(MAKE) -C build
	$(MAKE) -j1 -C build install

build/Makefile:
	rm -rf build
	mkdir build
	cd build && CC=$(CROSS)-gcc CFLAGS="-D__FILENAME_MAX__=64 -D__BUFSIZ__=128 -g -march=octeon3 -Os -fno-asynchronous-unwind-tables" ../newlib-1.18.0/newlib/configure --host=$(CROSS) --target=$(CROSS) --disable-multilib --disable-newlib-io-float --silent --prefix=$(BDK_ROOT)/libc

clean:
	rm -rf build mipsisa64-octeon-elf

