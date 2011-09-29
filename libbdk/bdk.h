#ifndef __BDK_H__
#define __BDK_H__

/**
 * @file
 *
 * Master include file for all BDK function.
 *
 * <hr>$Revision: 49448 $<hr>
 */

#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "../libbdk-arch/bdk-arch.h"
#include "../libbdk-os/bdk-os.h"
#ifndef BDK_BUILD_HOST
#include "../libbdk-hal/bdk-hal.h"
#include "../libbdk-dram/bdk-dram.h"
#include "bdk-functions.h"
#else
#include "../libbdk-hal/bdk-swap.h"
#endif
#include "../libbdk-lua/bdk-lua.h"

/**
 * @mainpage
 *
 * This document goes through the internal details of the BDK.  Its purpose is
 * to serve as a API reference for people writing applications. Users of the
 * BDK's binary applications do not need these details.
 */

#endif
