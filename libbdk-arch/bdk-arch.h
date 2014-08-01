#ifndef __BDK_ARCH_H__
#define __BDK_ARCH_H__

/**
 * @file
 *
 * Master include file for architecture support. Use bdk.h
 * instead of including this file directly.
 *
 * <hr>$Revision: 49448 $<hr>
 */

#ifndef __BYTE_ORDER
    #if !defined(__ORDER_BIG_ENDIAN__) || !defined(__ORDER_LITTLE_ENDIAN__) || !defined(__BYTE_ORDER__)
        #error Unable to determine Endian mode
    #elif __BYTE_ORDER__ == __ORDER_BIG_ENDIAN__
        #define __BYTE_ORDER __ORDER_BIG_ENDIAN__
    #elif __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        #define __BYTE_ORDER __ORDER_LITTLE_ENDIAN__
    #else
        #error Unable to determine Endian mode
    #endif
    #define __BIG_ENDIAN    __ORDER_BIG_ENDIAN__
    #define __LITTLE_ENDIAN __ORDER_LITTLE_ENDIAN__
#endif

#include "bdk-require.h"
#include "bdk-swap.h"
#ifndef BDK_BUILD_HOST
#include "bdk-asm.h"
#endif

#define SYSTEM_REGISTER(name, op0, op1, crn, crm, op2, ...)
#define INCLUDE_SYSTEM_REGISTER_TYPEDEFS 1
#include "bdk-sysreg.h"
#undef INCLUDE_SYSTEM_REGISTER_TYPEDEFS
#undef SYSTEM_REGISTER

#include "bdk-model.h"
#include "bdk-numa.h"
#include "bdk-csr.h"
#include "bdk-warn.h"
#include "bdk-csrs.h"
#include "bdk-version.h"
#ifndef BDK_BUILD_HOST
#include "bdk-fuse.h"
#include "bdk-feature.h"
#endif

#endif
