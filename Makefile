ifndef BDK_ROOT
    export BDK_ROOT:=$(shell pwd)
    $(info BDK_ROOT not set, assuming $(BDK_ROOT))
endif
ifdef BDK_CLANG_ROOT
    $(info BDK_CLANG_ROOT set, using LLVM tools)
else
    #$(info BDK_CLANG_ROOT not set, using GNU tools)
endif
include $(BDK_ROOT)/libbdk/bdk.mk

TFTPBOOT?=/tftpboot/

.PHONY: all
all: version
	$(MAKE) -C libc
	$(MAKE) -C libbdk
	$(MAKE) -C utils
	$(MAKE) -C apps
	$(MAKE) -C boards

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
	$(MAKE) -C apps clean
	$(MAKE) -C boards clean
	$(MAKE) -C docs clean
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

#
# The release target creates a tar of the source. It only works if a tag
# exactly matches the current branch head
#

.PHONY: release
release: all docs
	cp target-bin/bdk.bin $(BUILD_REV).bin
	md5sum $(BUILD_REV).bin > $(BUILD_REV).bin.md5
	git archive --format=tar --prefix=$(BUILD_REV)/ $(BUILD_REV) | tar -x
	cp -a docs/api-docs docs/lua-modules docs/*.pdf $(BUILD_REV)/docs/
	cp $(BUILD_REV).bin $(BUILD_REV).bin.md5 $(BUILD_REV)/
	tar -zcf $(BUILD_REV)-source.tgz $(BUILD_REV)
	md5sum $(BUILD_REV)-source.tgz > $(BUILD_REV)-source.tgz.md5

#
# User targets to run Asim
#

.PHONY: run # Runs normal-generic.bin
run: run-asim

.PHONY: run-normal # Runs normal-ebb8800.bin
run-normal: ASIM_IMAGE=$(BDK_ROOT)/target-bin/normal-ebb8800.bin
run-normal: ASIM_ELF=$(BDK_ROOT)/apps/diagnostics/app
run-normal: run-asim

#
# Defines controlling the command line for Asim
#
ASIM_CHIP ?= CN88XX:1.0
ASIM_IMAGE = $(BDK_ROOT)/target-bin/bdk.bin
ASIM_ELF = $(BDK_ROOT)/apps/diagnostics/app
ASIM_ENV = ASIM_CHIP=$(ASIM_CHIP)
ASIM_ENV += UART0PORT=2000
ASIM_ENV += UART1PORT=2001
ASIM_ENV += BIN_IMAGE=$(ASIM_IMAGE)
ASIM_ENV += SYMBOL_IMAGE=$(ASIM_ELF)
ASIM_SCRIPT = $(firstword $(subst :, ,$(ASIM_CHIP))).asim
ASIM_CMD = $(ASIM_ENV) $(ASIM)/asim -e $(ASIM_SCRIPT)
export ASIM_PCI_EA_CAP=1

#
# Target to run asim. Use other targets to change defines before executing this target
#
.PHONY: run-asim
run-asim:
ifndef ASIM
	echo ERROR: Define ASIM in the environment, the directory of asim && false
endif
	echo $(ASIM_CMD)
	$(ASIM_CMD)

#
# Determine the BDK version based on the last change in the version
# control system. This supports "git". It will need  changes for
# any other version control.
#
# BUILD_REV is a string representing the revision in version control
# BUILD_BRANCH is a string representing the branch in version control
#
ifeq ($(shell test -d .git;echo $$?),0)
    # Using git
    BUILD_REV := $(shell git describe --always --dirty)
    BUILD_BRANCH := $(shell git describe --all)
else
    # Don't know the version control system
    BUILD_REV=unknown
    BUILD_BRANCH=$(shell pwd)
endif
BUILD_DATE=$(shell date -u)
# Build the full BDK version string
DISPLAY_VERSION = "$(BUILD_REV), Branch: $(BUILD_BRANCH), Built: $(BUILD_DATE)"

.PHONY: version
version:
	echo "return \"$(DISPLAY_VERSION)\"" > lua-modules/bdk-version.lua
	echo "const char bdk_version_str[] = \"$(DISPLAY_VERSION)\";" > libbdk-arch/bdk-version.c

.PHONY: emu
emu:
	od -Ax -vtx1 -w1 target-bin/bdk.bin | cut -d " " -f 2 > thunder-emmc-ascii.img
	scp thunder-emmc-ascii.img dev001:emulator_images/
	ssh dev001 chmod o+r emulator_images/thunder-emmc-ascii.img

