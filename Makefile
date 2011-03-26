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

.PHONY: tftp
tftp: all
	$(MAKE) -C bdk-boot tftp

ifeq ($(shell test -d .git;echo $$?),0)
    BUILD_REV := $(shell git svn info | grep "Last Changed Rev:")
    BUILD_REV := $(word 4, $(BUILD_REV))
    BUILD_DATE := $(shell git svn info | grep "Last Changed Date:")
    BUILD_DATE := $(subst -, ,$(word 4, $(BUILD_DATE)))
else ifeq ($(shell test -d .svn;echo $$?),0)
    BUILD_REV := $(shell svn info | grep "Last Changed Rev:")
    BUILD_REV := $(word 4, $(BUILD_REV))
    BUILD_DATE := $(shell svn info | grep "Last Changed Date:")
    BUILD_DATE := $(subst -, ,$(word 4, $(BUILD_DATE)))
else
    BUILD_REV = "unknown"
    BUILD_DATE = "0000 00 00"
endif
VERSION = "$(word 1, $(BUILD_DATE)).$(word 2, $(BUILD_DATE))"
FULL_VERSION = "$(VERSION)-r$(BUILD_REV)"
RELEASE_DIR = "octeon-bdk-$(VERSION)"

.PHONY: release
release: all
	echo "Release $(VERSION) FULL_VERSION=$(FULL_VERSION) RELEASE_DIR=$(RELEASE_DIR)"
	rm -rf $(RELEASE_DIR)
	# Copy Docs
	mkdir -p $(RELEASE_DIR)/docs
	cp -a docs/lua $(RELEASE_DIR)/docs/
	cp -a docs/luasocket $(RELEASE_DIR)/docs/
	cp docs/*.html $(RELEASE_DIR)/docs/
	cp docs/*.png $(RELEASE_DIR)/docs/
	sed "s/VERSION/$(FULL_VERSION)/g" < docs/readme.txt > $(RELEASE_DIR)/readme.txt
	echo "$(VERSION)" > $(RELEASE_DIR)/version.txt
	# Copy host binaries
	mkdir -p $(RELEASE_DIR)/bin
	cp utils/scripts/bdk-remote.lua $(RELEASE_DIR)/bin/bdk-remote
	cp utils/scripts/bdk-debug.lua $(RELEASE_DIR)/bin/bdk-debug
	cp utils/scripts/bdk-update-header.py $(RELEASE_DIR)/bin/bdk-update-header
	cp utils/bdk-lua/bdk-lua $(RELEASE_DIR)/bin/
	# Copy host examples
	cp -r examples $(RELEASE_DIR)/
	# Copy target binaries
	mkdir -p $(RELEASE_DIR)/target-bin
	cp bdk-boot/bdk-boot $(RELEASE_DIR)/target-bin/
	cp bdk-boot/bdk-boot.bin $(RELEASE_DIR)/target-bin/
	cp bdk-boot/bdk-boot.map $(RELEASE_DIR)/target-bin/
	# Copy rom dir
	cp -a rom $(RELEASE_DIR)/
	# Copy SciTE
	mkdir -p $(RELEASE_DIR)/utils
	cp -a utils/bdk-scite $(RELEASE_DIR)/utils/
	cp -a bin/bdk-scite $(RELEASE_DIR)/bin/
	# Delete svn dirs
	find $(RELEASE_DIR) -name .svn -print0 | xargs -0 rm -rf
	# Create release tar
	tar -zcf "octeon-bdk-$(FULL_VERSION).tgz" $(RELEASE_DIR)
	rm -rf $(RELEASE_DIR)


