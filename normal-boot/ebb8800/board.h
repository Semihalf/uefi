#ifndef __BOARD_H__
#define __BOARD_H__

/* If non-zero, enable a watchdog timer to reset the chip ifwe hang during init.
   Value is in 262144 SCLK cycle intervals, max of 16 bits */
#define WATCHDOG_TIMEOUT 0

/* Name of DRAM config for master node 0 */
#define DRAM_NODE0 ebb8800
/* Name of DRAM config for slave node 1 */
#define DRAM_NODE1 ebb8800

#include "watchdog.h"

#endif /* __BOARD_H__ */
