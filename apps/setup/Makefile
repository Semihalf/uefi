include $(BDK_ROOT)/libbdk/bdk.mk

SRC =app.c
SRC+=$(wildcard menu-*.c)
OBJ=$(SRC:.c=.o)

setup.bin: app.bin
	$(BDK_ROOT)/bin/bdk-update-romfs $@ $^

app: $(OBJ) $(BDK_ROOT)/libbdk/libbdk.a

clean:
	rm -f $(OBJ) *.map *.bin app
