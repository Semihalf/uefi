
The files in this directory are binary images for running on THUNDERX.

bdk.bin:

Image for initially booting a board the first time.  Install this image at
the beginning of either SPI NOR or eMMC.  This image is generic enough to
boot on any CN88XX based board.  All hardware configuration is done
through a menu based interface.  Once booted, use this image to test
specific IO paths by hand.  Once one board is tested out, follow the BDK
documentation on how to customize the BDK for your board.  After
customization, switch to the normal.bin image.

normal.bin:

Image for booting THUNDERX with normal software.  Before this image can
work, you must have followed the steps in the BDK documentation to
customize the BDK for your board.  The source for this image is in
"normal-boot".  It will need customization for your board.  Specifically,
this image will not work until DRAM initialization has been ported and
normal-boot/boot-stub.c is updated with the proper DRAM configuration
name.  Install this image at the beginning of either SPI NOR or eMMC.

mio_boot_rom:

This image is not useful for hardware boards.  It is used when booting the
above images in the THUNDERX simulator.

