ifndef BDK_ROOT
$(error Define BDK_ROOT in the environment)
endif

.PHONY: all
all:
	$(MAKE) -C libc
	$(MAKE) -C libbdk
	$(MAKE) -C bdk-boot
	$(MAKE) -C utils
	$(MAKE) -C docs

.PHONY: clean
clean:
	$(MAKE) -C libbdk clean
	$(MAKE) -C bdk-boot clean
	$(MAKE) -C utils clean
	$(MAKE) -C docs clean

.PHONY: distclean
distclean: clean
	$(MAKE) -C libc clean
	$(MAKE) -C libbdk distclean

