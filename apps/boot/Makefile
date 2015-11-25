include $(BDK_ROOT)/libbdk/bdk.mk

boot.bin: app.bin
	if [ `stat -c %s $^` -gt 196608 ]; then echo "ERROR: $^ image must be 192KB or less";exit 1;fi
	$(BDK_ROOT)/bin/bdk-update-romfs $@ $^

app: app.o $(BDK_ROOT)/libbdk/libbdk.a
%.o: %.d
-include app.d

clean:
	rm -f *.o *.d *.map *.bin app
