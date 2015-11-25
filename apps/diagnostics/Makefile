include $(BDK_ROOT)/libbdk/bdk.mk

diagnostics.bin: app.bin lua/*
	$(BDK_ROOT)/bin/bdk-update-romfs $@ $^ lua/*

app: app.o $(BDK_ROOT)/libbdk/libbdk.a
%.o: %.d
-include app.d

clean:
	rm -f *.o *.d *.map *.bin app
