include $(BDK_ROOT)/libbdk/bdk.mk

pcie-dma-test.bin: pcie-dma-test
pcie-dma-test: pcie-dma-test.o $(BDK_ROOT)/libbdk/libbdk.a

clean:
	rm -f *.o pcie-dma-test pcie-dma-test.bin pcie-dma-test.map

tftp: pcie-dma-test.bin
	cp pcie-dma-test.bin /tftpboot/

