include $(BDK_ROOT)/libbdk/bdk.mk

cortina-objs =	driver/cortina-bdk.o \
				driver/cs4224_api.o \
				driver/cs_rtos.o

cortina-app.bin: app.bin images/cortina.img
	$(BDK_ROOT)/bin/bdk-update-romfs $@ $^ images/cortina.inf

app: app.o $(cortina-objs) $(BDK_ROOT)/libbdk/libbdk.a
%.o: %.d
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(MAKECMDGOALS),distclean)
-include app.d
endif
endif

images/cortina.img:
	images/cortina-convert.py images/cortina-latest.txt images/cortina.img

clean:
	rm -f *.o *.d *.map *.bin app $(cortina-objs)
