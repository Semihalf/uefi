
The files in this directory are binary images for running on OCTEON
targets.  The files bdk-*-no-romfs.bin are the base file for each
image.  The other image, bdk-*.bin, is bdk-*-no-romfs.bin with various
files added from the directories under rom/.  The script
bdk-update-all creates or updates these images.

bdk-*-no-romfs:
	ELF file with symbols for use with debuggers

bdk-*-no-romfs.bin:
	Image file used as a base for other bin images

bdk-*-no-romfs.map:
	Linker map file

bdk-*.bin:
	bdk-*-no-romfs.bin with files added from rom/*

