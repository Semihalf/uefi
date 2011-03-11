#ifndef __ARCH_CC_H__
#define __ARCH_CC_H__

/* BDK description of the compile environment for lwip */

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#define __LINUX_ERRNO_EXTENSIONS__ 1
#include <sys/errno.h>
#undef __LINUX_ERRNO_EXTENSIONS__

#ifndef ENSRNOTFOUND
#define ENSRNOTFOUND            163 /* Domain name not found */
#endif

typedef uint8_t u8_t;
typedef uint16_t u16_t;
typedef uint32_t u32_t;
typedef int8_t s8_t;
typedef int16_t s16_t;
typedef int32_t s32_t;
typedef long mem_ptr_t;

#define U16_F "hu"
#define S16_F "hd"
#define X16_F "hx"
#define U32_F "u"
#define S32_F "d"
#define X32_F "x"
#define SZT_F "lu"

#define BYTE_ORDER BIG_ENDIAN
#define LWIP_CHKSUM_ALGORITHM 2

/* Compiler hints for packing structures */
#define PACK_STRUCT_FIELD(x)    x
#define PACK_STRUCT_STRUCT  __attribute__((packed))
#define PACK_STRUCT_BEGIN
#define PACK_STRUCT_END

#define LWIP_PLATFORM_DIAG(x)   do { printf x;} while (0)
#define LWIP_PLATFORM_ASSERT(x) do { printf("Assert \"%s\" failed at line %d in %s\n", x, __LINE__, __FILE__); abort(); } while (0)

#endif
