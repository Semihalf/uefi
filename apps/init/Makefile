include $(BDK_ROOT)/libbdk/bdk.mk

init.bin: app.bin
	$(BDK_ROOT)/bin/bdk-update-romfs $@ $^

app: app.o $(BDK_ROOT)/libbdk/libbdk.a
%.o: %.d
-include app.d

clean:
	rm -f *.o *.d *.map *.bin app
