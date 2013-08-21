include $(BDK_ROOT)/libbdk/bdk.mk

ifeq ($(SIM),cn78xx)
	NUMCORES=48
else
	NUMCORES=4
endif

MAX_CYCLE = $(shell let i=1500000*$(NUMCORES) && echo $$i)
GREP_BEGIN = $(shell for ((i=0; i<${NUMCORES}; i++)); do echo " && grep \"Core $$i beginning crypto\" test-crypto.log"; done)
GREP_END = $(shell for ((i=0; i<${NUMCORES}; i++)); do echo " && grep \"PP$$i: stopping due to BREAK instruction\" test-crypto-sim.log"; done)

crypto.bin: crypto
crypto: crypto.o $(BDK_ROOT)/libbdk/libbdk.a

clean:
	rm -f *.o crypto crypto.bin crypto.map

tftp: crypto.bin
	cp crypto.bin /tftpboot/

run: crypto.bin
	$(SIMULATOR) -ld0x1fc00000:crypto -ld0x1fc00000:crypto.bin -ld0:0x400000 -modes=fastboot,pass1 -quiet -numcores=$(NUMCORES)

test: crypto.bin
	$(OCTEON_ROOT)/host/bin/oct-uart-io -b test-crypto.log &
	$(SIMULATOR) -ld0x1fc00000:crypto -ld0x1fc00000:crypto.bin -ld0:0x400000 -modes=fastboot,pass1 -quiet -numcores=$(NUMCORES) -maxcycles=$(MAX_CYCLE) -uart0=2020 > test-crypto-sim.log
	true $(GREP_BEGIN)
	grep 'Plaintext: "Original plaintext message"' test-crypto.log
	grep "MD5:      1517fa5c261777f967f2c7c034a13fd4" test-crypto.log
	grep "SHA1:     4964868fb28c4fdb08afa18c462e4c2c53b9c0ca" test-crypto.log
	grep "3des:     3fa40e8a984d48153fa40e8a984d4815" test-crypto.log
	grep "3des cbc: e5c7cdde872bf27cbc3e81b5aaa5190c" test-crypto.log
	grep "aes:      f8a4ba8e3feab9b1d63e0d1f67b00808f8a4ba8e3feab9b1d63e0d1f67b00808" test-crypto.log
	grep "aes cbc:  e5a82dea368354dcb2982f24ed13bc170b4256f2222e06362e54096ace81568f" test-crypto.log
	grep "kasumi:   df1f9b251c0bf45f" test-crypto.log
	grep "kasumi cbc: 86e5030dee2524f96d88a257350ad6493fb6337a9d7c329b5b1bb9785cd1808f" test-crypto.log
	grep "sms4:     681edf34d206965e86b3e94f536e4246681edf34d206965e86b3e94f536e4246" test-crypto.log
	grep "sms4 cbc: 0b15a6c212d85b67e7cdef840362e352896227805c2a1fad643b88bf7b2ba4af" test-crypto.log
	grep "snow3g:   5d5bfe75eb04f68ce0a12377ea00b37d47c6a0ba06309155086a859c4341b37c" test-crypto.log
	if grep "FAIL" test-crypto.log; then false; else true; fi
	true $(GREP_END)

