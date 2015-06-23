include $(BDK_ROOT)/libbdk/bdk.mk

DIR=$(BDK_ROOT)/target-bin

# Board specific modules and includes
ifndef BOARD_TYPE
$(info ********************************************************************************)
$(info * BOARD_TYPE not defined. Using default 'crb-2s')
$(info ********************************************************************************)
BOARD_TYPE=crb-2s
endif
BOARD_ROOT 	= $(BDK_ROOT)/chainboot/board/$(BOARD_TYPE)
BOARD_SRC   := $(wildcard $(BOARD_ROOT)/*.c)
BOARD_OBJS  := $(addsuffix .o, $(basename $(BOARD_SRC)))
CPPFLAGS 	+= -I $(BOARD_ROOT)

IMAGE_NAME=normal-${BOARD_TYPE}

.PHONY: all
all: ${DIR}/${IMAGE_NAME}.bin

#
# Rules for node 0 boot stub
#
${DIR}/${IMAGE_NAME}.bin: ${IMAGE_NAME}.bin
	cp ${IMAGE_NAME}.bin ${DIR}/${IMAGE_NAME}.bin

# Initial stage 0 chainloader
stage0.bin: chainloader.bin
	if [ `stat -c %s $^` -gt 196608 ]; then echo "ERROR: $^ image must be 192KB or less";exit 1;fi
	cp chainloader.bin stage0.bin

# BDK image
stage1.bin: boot-stub.bin
	cp boot-stub.bin stage1.bin

# Diagnostics image
stage2.bin: diagnostics.bin
	cp diagnostics.bin stage2.bin

${IMAGE_NAME}.bin: stage0.bin stage1.bin stage2.bin
	#
	# 1) 0x000000: 64KB unused by Thunder
	cat ptable-16MB-0x080000-0x300000-2.5M.img /dev/zero | head -q -c 65536 > ${IMAGE_NAME}.bin
	# 2) 0x010000: 64KB of CVM_CLIB header
	echo -n CVM_CLIB | cat - /dev/zero | head -q -c 65536 >> ${IMAGE_NAME}.bin
	# 3) 0x020000: 192KB of chainloader image (non-trusted)
	cat stage0.bin /dev/zero | head -q -c 196608 >> ${IMAGE_NAME}.bin
	# 4) 0x050000: 192KB of chainloader image (trusted)
	cat stage0.bin /dev/zero | head -q -c 196608 >> ${IMAGE_NAME}.bin

chainloader: chainloader.o $(BOARD_OBJS) $(BDK_ROOT)/libbdk/libbdk.a
diagnostics: diagnostics.o $(BOARD_OBJS) $(BDK_ROOT)/libbdk/libbdk.a
boot-stub: boot-stub.o $(BOARD_OBJS) $(BDK_ROOT)/libbdk/libbdk.a

clean:
	rm -f *.o *.map *.bin $(BOARD_ROOT)/*.o boot-stub diagnostics ${DIR}/${IMAGE_NAME}.bin

