#ifndef __BOARD_H__
#define __BOARD_H__

/**
 * This enumeration represents the status codes that can be reported to the BMC
 * for boot status.
 */
/* Set this to 0 for PCIe on QLMs 6-7. Set it to 1 for SATA when using the
   PCIe to SATA breakout card*/
#define USE_SATA_BREAKOUT_CARD 1

/* If non-zero, enable a watchdog timer to reset the chip ifwe hang during init.
   Value is in 262144 SCLK cycle intervals, max of 16 bits */
#define WATCHDOG_TIMEOUT 8010 /* 3sec at 700Mhz */

/* Name of DRAM config for master node 0 */
#define DRAM_NODE0 crb_1s
/* Name of DRAM config for slave node 1 */
//#define DRAM_NODE1 none

#include "watchdog.h"

#endif /* __BOARD_H__ */
