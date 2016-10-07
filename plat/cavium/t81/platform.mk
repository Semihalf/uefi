# Global platform name define, necessary at early init stages
DEFINES 		+=	-DT81

# Include common thunder platform's makefile helper
include plat/cavium/common/platform.mk

BL2_SOURCES		+=	plat/cavium/t81/thunder_ecam_cn81xx.c		\
