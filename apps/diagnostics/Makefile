include $(BDK_ROOT)/libbdk/bdk.mk

diagnostics.bin: app.bin lua/*
	$(BDK_ROOT)/bin/bdk-update-romfs $@ $^

app: app.o $(BDK_ROOT)/libbdk/libbdk.a
%.o: %.d
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(MAKECMDGOALS),distclean)
-include app.d
endif
endif

clean:
	rm -f *.o *.d *.map *.bin app
