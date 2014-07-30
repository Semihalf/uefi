CROSS=aarch64-thunder-elf

${CROSS}/lib/libc.a: build/Makefile
	$(MAKE) -C build
	$(MAKE) -j1 -C build install

build/Makefile:
	rm -rf build
	mkdir build
	cd build && CC=$(CROSS)-gcc CFLAGS="-D__FILENAME_MAX__=64 -D__BUFSIZ__=512 -g -Os -fno-asynchronous-unwind-tables" ../newlib-2.1.0/newlib/configure --host=$(CROSS) --target=$(CROSS) --disable-multilib --disable-newlib-io-float --silent --prefix=$(BDK_ROOT)/libc

clean:
	rm -rf build ${CROSS}

