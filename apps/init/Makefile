include $(BDK_ROOT)/libbdk/bdk.mk

init.bin: app.bin
	$(BDK_ROOT)/bin/bdk-update-romfs $@ $^

app: app.o $(BDK_ROOT)/libbdk/libbdk.a

clean:
	rm -f *.o *.map *.bin app
