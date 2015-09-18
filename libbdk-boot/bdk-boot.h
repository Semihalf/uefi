#ifndef __BDK_BOOT_H__
#define __BDK_BOOT_H__

/**
 * @file
 *
 * Master include file for functions related to boot images and
 * their operation. Any BDK based image booting on hardware has
 * a number of common tasks it needs to do. This header includes
 * the API functions in this catagory. Use bdk.h instead of
 * including this file directly.
 *
 * @defgroup boot Boot related support functions
 */

#include "bdk-boot-bgx.h"
#include "bdk-boot-pcie.h"
#include "bdk-boot-qlm.h"
#include "bdk-boot-status.h"
#include "bdk-boot-usb.h"
#include "bdk-image.h"
#include "bdk-watchdog.h"

#endif
