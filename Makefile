
.PHONY: libs
libs:
	$(MAKE) -C libc
	$(MAKE) -C libbdk

.PHONY: docs
docs:
	$(MAKE) -C docs

