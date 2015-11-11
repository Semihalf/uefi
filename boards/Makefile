#
# Create a list of the device tree DTB files we need
#
DTS_FILES=$(wildcard *.dts)
DTB_FILES=$(DTS_FILES:%.dts=%.dtb)

#
# The all target calls CREATE_COMMAND for each board in BOARDS
#
.PHONY: all
all:  $(DTB_FILES)
	$(BDK_ROOT)/bin/bdk-create-fatfs-image \
	    -o "$(BDK_ROOT)/target-bin/bdk.bin" \
	    -0 "$(BDK_ROOT)/apps/boot/boot.bin" \
	    -1 "$(BDK_ROOT)/apps/init/init.bin" \
	    -2 "$(BDK_ROOT)/apps/diagnostics/diagnostics.bin" \
	    -3 "$(BDK_ROOT)/apps/setup/setup.bin" \
	    -c "$(DTB_FILES)"

#
# This assumes that all binaries in target-bin that match our naming
# pattern should be deleted.
#
clean:
	rm -f $(BDK_ROOT)/target-bin/bdk.bin $(DTB_FILES)

%.dtb: %.dts *.dtsi
	dtc -I dts -O dtb -o $@ $<
