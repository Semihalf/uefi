#ifndef __BDK_HAL_H__
#define __BDK_HAL_H__

/**
 * @file
 *
 * Master include file for hardware support. Use bdk.h instead
 * of including this file directly.
 *
 * <hr>$Revision: 49448 $<hr>
 *
 * @defgroup hal Hardware abstraction layer
 */

/* Global define to control if the BDK configures units to send
    don't write back requests for freed buffers. Set to 1 to enable
    DWB, 0 to disable them. As the BDK normally fits inside L2, sending
    DWB just causes more L2 operations without benefit */
#define BDK_USE_DWB 0

#include "bdk-access.h"
#include "bdk-utils.h"
#include "bdk-config.h"
#include "bdk-atomic.h"
#include "bdk-spinlock.h"
#include "bdk-clock.h"
#include "bdk-crc.h"
#include "bdk-error-report.h"
#include "bdk-gpio.h"
#include "device/bdk-device.h"
#include "if/bdk-if.h"
#include "bdk-ecam.h"
#include "bdk-fpa.h"
#include "bdk-pki.h"
#include "bdk-pko.h"
#include "bdk-sso.h"
#include "bdk-nic.h"
#include "bdk-key.h"
#include "bdk-l2c.h"
#include "bdk-mdio.h"
#include "bdk-mpi.h"
#include "bdk-mmc.h"
#include "bdk-pcie.h"
#include "bdk-qlm.h"
#include "bdk-rng.h"
#include "bdk-sata.h"
#include "bdk-twsi.h"
#include "bdk-usb.h"
#include "bdk-access-native.h"
#include "bdk-tns.h"

#endif
