
CFLAGS = -g -O3 -W -Wall -Wno-unused-parameter -D_GNU_SOURCE -I ../lib $(EXTRA_CFLAGS)

ifndef DIR
DIR=.
LIBS := ../lib/libocteon-remote.a
else
LIBS := $(DIR)/libocteon-remote.a
endif
LIBS_CXX := ${LIBS}

ifndef CROSS
ifeq (1,${shell grep -q -s "Red Hat Linux release 9" /etc/redhat-release && echo 1})
CFLAGS+= -static
LIBS_FLAGS += -lc -lnss_files -lnss_dns -lresolv
LIBS_CXX += -Wl,-lstdc++,-lc,-lnss_files,-lnss_dns,-lresolv
endif
endif

CROSS=
CC=$(CROSS)gcc
CXX=$(CROSS)g++
STRIP=$(CROSS)strip

BINS = \
	$(DIR)/oct-remote-core \
	$(DIR)/oct-remote-load \
	$(DIR)/oct-remote-memory \
	$(DIR)/oct-remote-reset \
	$(DIR)/oct-remote-save \
	$(DIR)/oct-remote-csr \
	$(DIR)/oct-remote-boot

.PHONY: all
all: $(BINS)
	$(MAKE) -C ddr-tune-files
	- $(STRIP) $(BINS)
	- sudo chown -f root $(BINS)
	- sudo chmod -f +s,g+r,o+r $(BINS)

$(DIR)/oct-remote-boot: $(LIBS) oct-remote-boot.c oct-remote-common.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS) $(LIBS_FLAGS)
$(DIR)/oct-remote-core: $(LIBS) oct-remote-core.c oct-remote-common.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS) $(LIBS_FLAGS)
$(DIR)/oct-remote-csr: $(LIBS) oct-remote-csr.c oct-remote-common.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS) $(LIBS_FLAGS)
$(DIR)/oct-remote-load: $(LIBS) oct-remote-load.c oct-remote-common.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS) $(LIBS_FLAGS)
$(DIR)/oct-remote-memory: $(LIBS) oct-remote-memory.c oct-remote-common.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS) $(LIBS_FLAGS)
$(DIR)/oct-remote-reset: $(LIBS) oct-remote-reset.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS) $(LIBS_FLAGS)
$(DIR)/oct-remote-save: $(LIBS) oct-remote-save.c oct-remote-common.c
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS) $(LIBS_FLAGS)

.PHONY: clean
clean:
	rm -f $(BINS)
