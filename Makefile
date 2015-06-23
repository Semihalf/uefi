ifndef BDK_ROOT
    export BDK_ROOT:=$(shell pwd)
    $(info BDK_ROOT not set, assuming $(BDK_ROOT))
endif
include $(BDK_ROOT)/libbdk/bdk.mk

TFTPBOOT?=/tftpboot/

.PHONY: all
all: version
	$(MAKE) -C libc
	$(MAKE) -C libbdk
	$(MAKE) -C utils
	$(MAKE) -C bdk-boot
	$(MAKE) -C normal-boot BOARD_TYPE=crb-1s
	$(MAKE) -C normal-boot BOARD_TYPE=crb-2s
	$(MAKE) -C normal-boot BOARD_TYPE=ebb8800
	$(MAKE) -C normal-boot BOARD_TYPE=ebb8804
#	$(MAKE) -C screen # REMOVE-RELEASE

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
	$(MAKE) -C normal-boot BOARD_TYPE=crb-1s clean
	$(MAKE) -C normal-boot BOARD_TYPE=crb-2s clean
	$(MAKE) -C normal-boot BOARD_TYPE=ebb8800 clean
	$(MAKE) -C normal-boot BOARD_TYPE=ebb8804 clean
	$(MAKE) -C screen clean # REMOVE-RELEASE
	$(MAKE) -C docs clean # REMOVE-RELEASE
	rm -f target-bin/*.bin

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

.PHONY: run
run:
ifndef ASIM
	echo ERROR: Define ASIM in the environment, the directory of asim && false
endif
	UART0PORT=2000 UART1PORT=2001 BIN_IMAGE=$(BDK_ROOT)/target-bin/bdk.bin SYMBOL_IMAGE=$(BDK_ROOT)/bdk-boot/diagnostics $(ASIM)/asim -e bdk.asim

.PHONY: run-normal
run-normal:
ifndef ASIM
	echo ERROR: Define ASIM in the environment, the directory of asim && false
endif
	UART0PORT=2000 UART1PORT=2001 BIN_IMAGE=$(BDK_ROOT)/target-bin/normal-ebb8800.bin SYMBOL_IMAGE=$(BDK_ROOT)/normal-boot/ebb8800/diagnostics $(ASIM)/asim -e bdk.asim

.PHONY: run-screen
run-screen:
ifndef ASIM
	echo ERROR: Define ASIM in the environment, the directory of asim && false
endif
	UART0PORT=2000 UART1PORT=2001 BIN_IMAGE=$(BDK_ROOT)/target-bin/screen-standalone.bin SYMBOL_IMAGE=$(BDK_ROOT)/screen/screen $(ASIM)/asim -e bdk.asim


#
# Determine the BDK version based on the last change in the version
# control system. This supports "git svn" and "svn". It will need
# changes for any other version control.
#
# BUILD_REV is a string representing the revision in version control
# BUILD_DATE is the last change date, formatted as "YYYY MM DD"
#
ifeq ($(shell test -d .git;echo $$?),0)
    # Using git, check for git svn or raw git
    ifneq ($(shell  git svn find-rev HEAD;echo $$?),0)
      # Using git svn
      BUILD_REV := $(shell git svn info | grep "Last Changed Rev:")
      BUILD_REV := "r$(word 4, $(BUILD_REV))"
      BUILD_DATE := $(shell git svn info | grep "Last Changed Date:")
      BUILD_DATE := $(subst -, ,$(word 4, $(BUILD_DATE)))
      BUILD_BRANCH := $(shell git svn info | grep "URL:")
      BUILD_BRANCH := $(word 2, $(BUILD_BRANCH))
      BUILD_BRANCH := $(subst /, ,$(BUILD_BRANCH))
      BUILD_BRANCH := $(lastword $(BUILD_BRANCH))
    else
      # Using raw git
      BUILD_REV := $(shell git show | grep "^commit")
      BUILD_REV := "$(word 2, $(BUILD_REV))"
      BUILD_DATE=$(shell date "+%Y %m %d")
      BUILD_BRANCH := $(shell git status | grep "On branch")
      BUILD_BRANCH := $(word 4, $(BUILD_BRANCH))
    endif
else ifeq ($(shell test -d .svn;echo $$?),0)
    # Using subversion
    BUILD_REV := $(shell svn info | grep "Last Changed Rev:")
    BUILD_REV := "r$(word 4, $(BUILD_REV))"
    MOD := $(shell svnversion | perl -e 'while (<>){s/[0-9]*//;print}')
    BUILD_REV := $(BUILD_REV)$(MOD)
    BUILD_DATE := $(shell svn info | grep "Last Changed Date:")
    BUILD_DATE := $(subst -, ,$(word 4, $(BUILD_DATE)))
    BUILD_BRANCH := $(shell svn info | grep "URL:")
    BUILD_BRANCH := $(word 2, $(BUILD_BRANCH))
    BUILD_BRANCH := $(subst /, ,$(BUILD_BRANCH))
    BUILD_BRANCH := $(lastword $(BUILD_BRANCH))
else
    # Don't know, use the date as a backup
    BUILD_REV=unknown
    BUILD_DATE=$(shell date "+%Y %m %d")
    BUILD_BRANCH=$(shell pwd)
endif
UTC_DATE=$(shell date -u)
# Build the full BDK version string
VERSION = "$(word 1, $(BUILD_DATE)).$(word 2, $(BUILD_DATE))"
FULL_VERSION = "$(VERSION)-$(BUILD_REV)"
DISPLAY_VERSION = "$(FULL_VERSION), Branch: $(BUILD_BRANCH), Built: $(UTC_DATE)"
RELEASE_NAME = "thunderx-bdk"
RELEASE_DIR = "$(RELEASE_NAME)-$(VERSION)"

.PHONY: version
version:
	echo "return \"$(DISPLAY_VERSION)\"" > lua-modules/bdk-version.lua
	echo "const char bdk_version_str[] = \"$(DISPLAY_VERSION)\";" > libbdk-arch/bdk-version.c

.PHONY: release
release: all docs
	echo "Release $(VERSION) FULL_VERSION=$(FULL_VERSION) RELEASE_DIR=$(RELEASE_DIR)"
	rm -rf $(RELEASE_DIR)
	# Copy Docs
	mkdir -p $(RELEASE_DIR)/docs
	cp -a docs/lua $(RELEASE_DIR)/docs/
	cp -a docs/luasocket $(RELEASE_DIR)/docs/
	cp docs/*.pdf $(RELEASE_DIR)/docs/
	cp -a docs/lua-modules $(RELEASE_DIR)/docs/
	cp -a docs/api-docs $(RELEASE_DIR)/docs/
	sed "s/VERSION/$(FULL_VERSION)/g" < docs/readme.txt > $(RELEASE_DIR)/readme.txt
	echo "$(VERSION)" > $(RELEASE_DIR)/version.txt
	# Copy host binaries
	cp -a bin $(RELEASE_DIR)/
	# Copy target binaries
	cp -a target-bin $(RELEASE_DIR)/target-bin
	# Copy source code
	$(MAKE) -C libc clean
	cp -a lib* $(RELEASE_DIR)/
	cp -a utils $(RELEASE_DIR)/
	grep -v "REMOVE-RELEASE" Makefile > $(RELEASE_DIR)/Makefile
	# Copy boot stubs
	cp -a bdk-boot $(RELEASE_DIR)/
	cp -a normal-boot $(RELEASE_DIR)/
	# Copy lua-modules dir
	cp -a lua-modules $(RELEASE_DIR)/
	rm $(RELEASE_DIR)/lua-modules/*.luadoc
	# Delete svn dirs
	find $(RELEASE_DIR) -name .svn -print0 | xargs -0 rm -rf
	# Delete ".d", ".o", ".a", ".pch", "obj-*" files
	find $(RELEASE_DIR) -name "*.d" -print0 | xargs -0 rm -rf
	find $(RELEASE_DIR) -name "*.o" -print0 | xargs -0 rm -rf
	find $(RELEASE_DIR) -name "*.a" -print0 | xargs -0 rm -rf
	find $(RELEASE_DIR) -name "*.pch" -print0 | xargs -0 rm -rf
	find $(RELEASE_DIR) -name "obj-*" -print0 | xargs -0 rm -rf
	# Create release tar
	tar -zcf "$(RELEASE_NAME)-$(FULL_VERSION).tgz" $(RELEASE_DIR)
	rm -rf $(RELEASE_DIR)

.PHONY: emu
emu:
	od -Ax -vtx1 -w1 target-bin/bdk.bin | cut -d " " -f 2 > thunder-emmc-ascii.img
	scp thunder-emmc-ascii.img dev001:emulator_images/
	ssh dev001 chmod o+r emulator_images/thunder-emmc-ascii.img

