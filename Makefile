ifndef BDK_ROOT
$(error Define BDK_ROOT in the environment)
endif
include $(BDK_ROOT)/libbdk/bdk.mk

TFTPBOOT?=/tftpboot/

.PHONY: all
all: version
	$(MAKE) -C libc
	$(MAKE) -C libbdk
	$(MAKE) -C utils
	$(MAKE) -C bdk-boot
	$(BDK_ROOT)/bin/bdk-update-all

#
# Split docs out from all to allow build to reach tftp when docs fails.
#
.PHONY: docs
docs:
	$(MAKE) -C docs

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
	cp target-bin/*.bin $(TFTPBOOT)

.PHONY: suid
suid: all
	$(MAKE) -C utils/bdk-lua suid

RUN_SIM_ARGS =
#
# Use these to boot off Node 0
#
RUN_SIM_ARGS += -ld0x1fc00000:target-bin/bdk-full-no-romfs
RUN_SIM_ARGS += -ld0x1fc00000:target-bin/bdk-full.bin
RUN_SIM_ARGS += -ld0:0x1000000
#
# Use these to boot off Node 1
#
#RUN_SIM_ARGS += -remoteboot=0xd
#RUN_SIM_ARGS += -ld0x100101fc00000:target-bin/bdk-full-no-romfs
#RUN_SIM_ARGS += -ld0x100101fc00000:target-bin/bdk-full.bin
#RUN_SIM_ARGS += -ld0x0010000000000:0x1000000
#RUN_SIM_ARGS += -ld0:0x100 # FIXME: Why is this needed
#
# Common sim options
#
RUN_SIM_ARGS += -modes=fastboot,pass1
RUN_SIM_ARGS += -numcores=1
RUN_SIM_ARGS += -noperf
RUN_SIM_ARGS += -quiet
RUN_SIM_ARGS += -trace=all
# Sim option for Node 0
RUN_SIM_ARGS += -serve=2000
RUN_SIM_ARGS += -uart0=2020
RUN_SIM_ARGS += -uart1=2030
ifeq ($(SIM),cn78xx)
    RUN_SIM_ARGS += -numnodes=4
    # Sim option for Node 0
    # Sim option for Node 1
    RUN_SIM_ARGS += -serve=1:2001
    RUN_SIM_ARGS += -uart0=1:2021
    RUN_SIM_ARGS += -uart1=1:2031
    # Sim option for Node 2
    RUN_SIM_ARGS += -serve=2:2002
    RUN_SIM_ARGS += -uart0=2:2022
    RUN_SIM_ARGS += -uart1=2:2032
    # Sim option for Node 3
    RUN_SIM_ARGS += -serve=3:2003
    RUN_SIM_ARGS += -uart0=3:2023
    RUN_SIM_ARGS += -uart1=3:2033
endif

.PHONY: run
run:
	$(SIMULATOR) $(RUN_SIM_ARGS)

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
    MOD := $(shell svnversion | perl -e 'while (<>){s/[0-9]*//;print}')
    BUILD_REV := $(BUILD_REV)$(MOD)
    BUILD_DATE := $(shell svn info | grep "Last Changed Date:")
    BUILD_DATE := $(subst -, ,$(word 4, $(BUILD_DATE)))
else
    BUILD_REV=unknown
    BUILD_DATE=0000 00 00
endif
VERSION = "$(word 1, $(BUILD_DATE)).$(word 2, $(BUILD_DATE))"
FULL_VERSION = "$(VERSION)-r$(BUILD_REV)"
RELEASE_NAME = "octeon3-bdk"
RELEASE_DIR = "$(RELEASE_NAME)-$(VERSION)"

.PHONY: version
version:
	echo "return \"$(FULL_VERSION)\"" > lua-modules/bdk-version.lua
	echo "const char bdk_version_str[] = \"$(FULL_VERSION)\";" > libbdk-arch/bdk-version.c

.PHONY: release
release: all docs
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
	cp -a docs/api-docs $(RELEASE_DIR)/docs/
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
	cp utils/bdk-luac/bdk-luac-x86 $(RELEASE_DIR)/bin/
	cp utils/bdk-luac/bdk-luac-octeon $(RELEASE_DIR)/bin/
	cp bin/bdk-lua $(RELEASE_DIR)/bin/bdk-lua
	cp bin/bdk-luac $(RELEASE_DIR)/bin/bdk-luac
	cp bin/bdk-update-all $(RELEASE_DIR)/bin/
	cp -a bin/bdk-menu $(RELEASE_DIR)/bin/
	# Copy target binaries
	mkdir -p $(RELEASE_DIR)/
	cp -a target-bin $(RELEASE_DIR)/target-bin
	rm $(RELEASE_DIR)/target-bin/ipemainc.elf
	# Copy rom dir
	cp -a rom $(RELEASE_DIR)/
	# Copy lua-modules dir
	cp -a lua-modules $(RELEASE_DIR)/
	rm $(RELEASE_DIR)/lua-modules/*.luadoc
	# Delete svn dirs
	find $(RELEASE_DIR) -name .svn -print0 | xargs -0 rm -rf
	# Create release tar
	tar -zcf "$(RELEASE_NAME)-$(FULL_VERSION).tgz" $(RELEASE_DIR)
	rm -rf $(RELEASE_DIR)


