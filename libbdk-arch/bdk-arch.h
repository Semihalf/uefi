#ifndef __BDK_ARCH_H__
#define __BDK_ARCH_H__

#ifndef __BYTE_ORDER
    #if defined(__BIG_ENDIAN) && !defined(__LITTLE_ENDIAN)
        #define __BYTE_ORDER __BIG_ENDIAN
    #elif !defined(__BIG_ENDIAN) && defined(__LITTLE_ENDIAN)
        #define __BYTE_ORDER __LITTLE_ENDIAN
        #define __BIG_ENDIAN 4321
    #elif !defined(__BIG_ENDIAN) && !defined(__LITTLE_ENDIAN)
        #define __BIG_ENDIAN 4321
        #define __BYTE_ORDER __BIG_ENDIAN
    #else
        #error Unable to determine Endian mode
    #endif
#endif

#include "bdk-asm.h"
#include "bdk-model.h"
#include "bdk-csr.h"
#include "bdk-warn.h"
#include "bdk-csrs.h"
#include "bdk-fuse.h"
#include "bdk-feature.h"

#endif
