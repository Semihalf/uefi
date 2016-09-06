# ***********************license start***********************************
# Copyright (c) 2003-2016  Cavium Inc. (support@cavium.com). All rights
# reserved.
#
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions are
# met:
#
#   * Redistributions of source code must retain the above copyright
#     notice, this list of conditions and the following disclaimer.
#
#   * Redistributions in binary form must reproduce the above
#     copyright notice, this list of conditions and the following
#     disclaimer in the documentation and/or other materials provided
#     with the distribution.
#
#   * Neither the name of Cavium Inc. nor the names of
#     its contributors may be used to endorse or promote products
#     derived from this software without specific prior written
#     permission.
#
# This Software, including technical data, may be subject to U.S. export
# control laws, including the U.S. Export Administration Act and its
# associated regulations, and may be subject to export or import
# regulations in other countries.
#
# TO THE MAXIMUM EXTENT PERMITTED BY LAW, THE SOFTWARE IS PROVIDED "AS IS"
# AND WITH ALL FAULTS AND CAVIUM INC. MAKES NO PROMISES, REPRESENTATIONS OR
# WARRANTIES, EITHER EXPRESS, IMPLIED, STATUTORY, OR OTHERWISE, WITH RESPECT
# TO THE SOFTWARE, INCLUDING ITS CONDITION, ITS CONFORMITY TO ANY
# REPRESENTATION OR DESCRIPTION, OR THE EXISTENCE OF ANY LATENT OR PATENT
# DEFECTS, AND CAVIUM SPECIFICALLY DISCLAIMS ALL IMPLIED (IF ANY) WARRANTIES
# OF TITLE, MERCHANTABILITY, NONINFRINGEMENT, FITNESS FOR A PARTICULAR
# PURPOSE, LACK OF VIRUSES, ACCURACY OR COMPLETENESS, QUIET ENJOYMENT,
# QUIET POSSESSION OR CORRESPONDENCE TO DESCRIPTION. THE ENTIRE  RISK
# ARISING OUT OF USE OR PERFORMANCE OF THE SOFTWARE LIES WITH YOU.
# **********************license end**************************************

#
# Create a list of the device tree DTB files we need
#
DTS_FILES=$(wildcard *.dts)
DTB_FILES=$(DTS_FILES:%.dts=%.dtb)
EXTRA_FILES=$(BDK_ROOT)/apps/cortina/cortina-app.bin

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
	    -x "$(EXTRA_FILES)" \
	    -c "$(DTB_FILES)"

#
# This assumes that all binaries in target-bin that match our naming
# pattern should be deleted.
#
clean:
	rm -f $(BDK_ROOT)/target-bin/bdk.bin $(DTB_FILES)

%.dtb: %.dts *.dtsi
	dtc -I dts -O dtb -o $@ $<
