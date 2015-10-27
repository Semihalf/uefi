#
# This is the list of boards to make images for. Add new boards here
# and create directories for them.
#
BOARDS=
BOARDS+=generic
BOARDS+=crb-1s
BOARDS+=crb-2s
BOARDS+=ebb8604
BOARDS+=ebb8800
BOARDS+=ebb8804
BOARDS+=inv-p3e003
BOARDS+=screen-ebb8604
BOARDS+=screen-ebb8800
BOARDS+=screen-ebb8804

#
# Create a list of the device tree DTB files we need
#
DTS_FILES=$(wildcard $(BOARDS:%=%/*.dts))
DTB_FILES=$(DTS_FILES:%.dts=%.dtb)

#
# This variable is the command line needed to pack all the files
# needed for an image into the image. The "$${b}" will be replaced
# by the board name on execution. Currently bdk-create-fatfs-image
# can't be run in parallel due to a FatFS temporary file.
#
CREATE_COMMAND="$(BDK_ROOT)/bin/bdk-create-fatfs-image"
CREATE_COMMAND+=-o "$(BDK_ROOT)/target-bin/normal-$${b}.bin"
CREATE_COMMAND+=-0 "$(BDK_ROOT)/apps/boot/boot.bin"
CREATE_COMMAND+=-1 "$(BDK_ROOT)/apps/init/init.bin"
CREATE_COMMAND+=-2 "$(BDK_ROOT)/apps/diagnostics/diagnostics.bin"
CREATE_COMMAND+=-3 "$(BDK_ROOT)/apps/setup/setup.bin"
CREATE_COMMAND+=-c "$${b}/$${b}*.dtb"
CREATE_COMMAND+=-l "lua-common/*.lua $${b}/lua/*.lua"

#
# The all target calls CREATE_COMMAND for each board in BOARDS
#
.PHONY: all
all:  $(DTB_FILES)
	for b in $(BOARDS); do \
	    $(CREATE_COMMAND); \
	done

#
# This assumes that all binaries in target-bin that match our naming
# pattern should be deleted.
#
clean:
	rm -f $(BDK_ROOT)/target-bin/normal-*.bin $(DTB_FILES)

%.dtb: %.dts
	dtc -I dts -O dtb -o $@ $^
