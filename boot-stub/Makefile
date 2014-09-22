include $(BDK_ROOT)/libbdk/bdk.mk

DIR=$(BDK_ROOT)/target-bin

TARGETS := boot-stub
TARGETS += ${DIR}/boot-stub.bin

.PHONY: all
all: ${TARGETS}

${DIR}/boot-stub.bin: boot-stub.bin
	mkdir -p ${DIR}
	cp boot-stub.bin ${DIR}/

boot-stub: boot-stub.o $(BDK_ROOT)/libbdk/libbdk.a

clean:
	rm -f *.o *.map *.bin ${TARGETS}

