ifndef BDK_ROOT
$(error Define BDK_ROOT in the environment)
endif
include $(BDK_ROOT)/libbdk/bdk.mk

.PHONY: all
all: version
	$(MAKE) -C libc
	$(MAKE) -C libbdk
	$(MAKE) -C utils
	$(MAKE) -C bdk-boot
	$(BDK_ROOT)/bin/bdk-update-all
	$(MAKE) -C docs

.PHONY: ppc
ppc:
	echo "Building bdk-lua-ppc (very slow)"
	$(MAKE) -C utils/bdk-lua ppc
	echo "Building bdk-luac-ppc (very slow)"
	$(MAKE) -C utils/bdk-luac ppc
	echo "Done with ppc"

.PHONY: clean
clean:
	$(MAKE) -C libbdk clean
	$(MAKE) -C utils clean
	$(MAKE) -C bdk-boot clean
	$(MAKE) -C docs clean

.PHONY: distclean
distclean: clean
	$(MAKE) -C libc clean
	$(MAKE) -C libbdk distclean

.PHONY: tftp
tftp: all
	cp target-bin/*.bin /tftpboot/

.PHONY: suid
suid: all
	$(MAKE) -C utils/bdk-lua suid

.PHONY: run
run:
	$(SIMULATOR) -ld0x1fc00000:target-bin/bdk-full-no-romfs -ld0x1fc00000:target-bin/bdk-full.bin -ld0:0x200000 -modes=fastboot,pass2 -uart0=2020 -noperf -quiet -serve=2000

.PHONY: run-min
run-min:
	$(SIMULATOR) -ld0x1fc00000:target-bin/bdk-minimal-no-romfs -ld0x1fc00000:target-bin/bdk-minimal.bin -ld0:0x100000 -modes=fastboot,pass2 -uart0=2020 -noperf -quiet -serve=2000

.PHONY: run-rtl
run-rtl:
	$(SIMULATOR) bdk-boot/bdk-reset-rtl -ld0:0x200000 -ld0:target-bin/bdk-full.bin -modes=pass2 -uart0=2020 -quiet -serve=2000

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

.PHONY: version
version:
	echo "return \"$(FULL_VERSION)\"" > lua-modules/bdk-version.lua

.PHONY: release
release: all # ppc needed as well
	PATH=$(PATH):~creese/bin $(MAKE) -C docs lua-modules
	echo "Release $(VERSION) FULL_VERSION=$(FULL_VERSION) RELEASE_DIR=$(RELEASE_DIR)"
	rm -rf $(RELEASE_DIR)
	# Copy Docs
	mkdir -p $(RELEASE_DIR)/docs
	cp -a docs/lua $(RELEASE_DIR)/docs/
	cp -a docs/luasocket $(RELEASE_DIR)/docs/
	cp docs/*.html $(RELEASE_DIR)/docs/
	rm $(RELEASE_DIR)/docs/bdk-faqs.html
	cp -a docs/images $(RELEASE_DIR)/docs/
	cp -a docs/lua-modules $(RELEASE_DIR)/docs/
	sed "s/VERSION/$(FULL_VERSION)/g" < docs/readme.txt > $(RELEASE_DIR)/readme.txt
	echo "$(VERSION)" > $(RELEASE_DIR)/version.txt
	# Copy host binaries
	mkdir -p $(RELEASE_DIR)/bin
	cp utils/scripts/bdk-remote.lua $(RELEASE_DIR)/bin/bdk-remote
	cp utils/scripts/bdk-debug.lua $(RELEASE_DIR)/bin/bdk-debug
	cp utils/scripts/bdk-record.lua $(RELEASE_DIR)/bin/bdk-record
	cp utils/scripts/bdk-update-romfs.py $(RELEASE_DIR)/bin/bdk-update-romfs
	cp utils/bdk-lua/bdk-lua-x86 $(RELEASE_DIR)/bin/
	cp utils/bdk-lua/bdk-lua-octeon $(RELEASE_DIR)/bin/
	cp utils/bdk-lua/bdk-lua-ppc $(RELEASE_DIR)/bin/
	cp utils/bdk-luac/bdk-luac-x86 $(RELEASE_DIR)/bin/
	cp utils/bdk-luac/bdk-luac-octeon $(RELEASE_DIR)/bin/
	cp utils/bdk-luac/bdk-luac-ppc $(RELEASE_DIR)/bin/
	cp bin/bdk-lua $(RELEASE_DIR)/bin/bdk-lua
	cp bin/bdk-luac $(RELEASE_DIR)/bin/bdk-luac
	cp bin/bdk-update-all $(RELEASE_DIR)/bin/
	cp -a bin/bdk-menu $(RELEASE_DIR)/bin/
	# Copy host examples
	cp -r examples $(RELEASE_DIR)/
	# Copy target binaries
	mkdir -p $(RELEASE_DIR)/
	cp -a target-bin $(RELEASE_DIR)/target-bin
	# Copy rom dir
	cp -a rom $(RELEASE_DIR)/
	# Copy lua-modules dir
	cp -a lua-modules $(RELEASE_DIR)/
	# Delete svn dirs
	find $(RELEASE_DIR) -name .svn -print0 | xargs -0 rm -rf
	# Create release tar
	tar -zcf "octeon-bdk-$(FULL_VERSION).tgz" $(RELEASE_DIR)
	rm -rf $(RELEASE_DIR)


