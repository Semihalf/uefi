# Global platform name define, necessary at early init stages
DEFINES 		+=	-DT83

# Include common thunder platform's makefile helper
include plat/cavium/common/platform.mk

BL2_SOURCES		+=	plat/cavium/t83/thunder_ecam_cn83xx.c		\
