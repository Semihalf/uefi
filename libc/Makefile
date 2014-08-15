CROSS=aarch64-thunderx-elf

NEWLIB_CONFIG := --host=$(CROSS)
NEWLIB_CONFIG += --target=$(CROSS)
NEWLIB_CONFIG += --silent
NEWLIB_CONFIG += --prefix=$(BDK_ROOT)/libc
NEWLIB_CONFIG += --disable-newlib-io-pos-args
NEWLIB_CONFIG += --disable-newlib-mb
NEWLIB_CONFIG += --disable-newlib-io-c99-formats
NEWLIB_CONFIG += --disable-newlib-register-fini
NEWLIB_CONFIG += --enable-newlib-io-long-long
NEWLIB_CONFIG += --disable-newlib-reent-small
NEWLIB_CONFIG += --disable-newlib-fseek-optimization
NEWLIB_CONFIG += --disable-newlib-wide-orient
NEWLIB_CONFIG += --disable-newlib-nano-malloc # Enabling causes stack alignment issues
NEWLIB_CONFIG += --enable-target-optspace
NEWLIB_CONFIG += --enable-newlib-multithread
NEWLIB_CONFIG += --disable-newlib-iconv
NEWLIB_CONFIG += --disable-multilib
NEWLIB_CONFIG += --disable-newlib-io-float
NEWLIB_CONFIG += --disable-malloc-debugging

${CROSS}/lib/libc.a: build/Makefile
	$(MAKE) -C build
	$(MAKE) -j1 -C build install

build/Makefile:
	rm -rf build
	mkdir build
	cd build && CC=$(CROSS)-gcc CFLAGS="-D__FILENAME_MAX__=64 -D__BUFSIZ__=512 -g -Os -fno-asynchronous-unwind-tables" ../newlib-2.1.0/newlib/configure  $(NEWLIB_CONFIG)

clean:
	rm -rf build ${CROSS}

