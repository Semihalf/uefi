# Global platform name define, necessary at early init stages
DEFINES 		+=	-DT98

# Include common thunder platform's makefile helper
include plat/cavium/common/platform.mk

BL2_SOURCES		+=	plat/cavium/t98/thunder_ecam_cn98xx.c		\
