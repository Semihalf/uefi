CFLAGS = -g -O3 -W -Wall -D_GNU_SOURCE  $(EXTRA_CFLAGS) -I${BDK_ROOT}

DIR=.
CROSS=
CC=$(CROSS)gcc
AR=$(CROSS)ar

.PHONY: all
all: $(DIR)/libocteon-remote.a

OBJ = $(DIR)/octeon-remote.o \
	$(DIR)/octeon-remote-map.o \
	$(DIR)/octeon-remote-debug-handler.o \
	$(DIR)/octeon-remote-gdbremote.o \
	$(DIR)/octeon-remote-pci.o \
	$(DIR)/octeon-remote-linux.o \
	$(DIR)/octeon-remote-mips-asm.o \
	$(DIR)/octeon-remote-macraigor.o \
	$(DIR)/octeon-remote-bdk.o

$(DIR)/libocteon-remote.a: $(OBJ)
	$(AR) -cr $@ $^

$(DIR)/octeon-remote.o: octeon-remote.c octeon-remote.h
$(DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(DIR)/octeon-remote-mips-asm.o: $(DIR)/mips-octeon_debug_handler.bin $(DIR)/mips-octeon2_debug_handler.bin $(DIR)/mips-octeon_profile_handler.bin
	$(CC) $(CFLAGS) -c -o $@ octeon-remote-mips-asm.S -I$(DIR)

$(DIR)/mips-%.o: mips-%.S
	mips64-octeon-linux-gnu-gcc -W -Wall -o $@ -c $<
$(DIR)/mips-%.bin: $(DIR)/mips-%.o
	mips64-octeon-linux-gnu-objcopy -j .text -O binary $< $@

.PHONY: clean
clean:
	rm -f $(DIR)/*.o $(DIR)/*.a $(DIR)/*.bin

