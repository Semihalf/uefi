#ifndef __BDK_HAL_H__
#define __BDK_HAL_H__

/**
 * @file
 *
 * Master include file for Octeon hardware support. Use bdk.h instead of
 * including this file directly.
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

/* BDK_DISABLE_QLM_JTAG disables all QLM JTAG functions, which is most
    useful when you are running RTL sims or need to never touch the
    QLM JTAG chains */
#ifndef BDK_DISABLE_QLM_JTAG
#define BDK_DISABLE_QLM_JTAG 0
#endif

#include "bdk-access.h"
#include "bdk-utils.h"
#include "bdk-config.h"
#include "bdk-atomic.h"
#include "bdk-spinlock.h"
#include "bdk-clock.h"
#include "bdk-scratch.h"
#include "bdk-fpa.h"
#include "bdk-cmd-queue.h"
#include "bdk-core.h"
#include "bdk-crc.h"
#include "bdk-dma-engine.h"
#include "bdk-error-report.h"
#include "bdk-fau.h"
#include "bdk-flash.h"
#include "bdk-gpio.h"
#include "bdk-higig.h"
#include "bdk-wqe.h"
#include "if/bdk-if.h"
#include "bdk-key.h"
#include "bdk-l2c.h"
#include "bdk-mdio.h"
#include "bdk-mpi.h"
#include "bdk-nand.h"
#include "bdk-pcie.h"
#include "bdk-pcie-eeprom.h"
#include "bdk-qlm.h"
#include "bdk-rng.h"
#include "bdk-swap.h"
#include "bdk-twsi.h"
#include "bdk-access-native.h"

#endif
