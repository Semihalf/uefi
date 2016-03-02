include $(BDK_ROOT)/libbdk/bdk.mk

SRC =app.c
SRC+=$(wildcard menu-*.c)
OBJ=$(SRC:.c=.o)
DEPS=$(SRC:.c=.d)
DEPS+=$(BDK_ROOT)/libbdk/bdk.d

setup.bin: app.bin
	$(BDK_ROOT)/bin/bdk-update-romfs $@ $^

app: $(OBJ) $(BDK_ROOT)/libbdk/libbdk.a
%.o: %.d
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(MAKECMDGOALS),distclean)
-include $(DEPS)
endif
endif

clean:
	rm -f $(OBJ) *.d *.map *.bin app
